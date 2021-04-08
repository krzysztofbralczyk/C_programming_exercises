#include "file_reader.h"
#include "tested_declarations.h"
#include "rdebug.h"

#define END_OF_BOOTSECTOR 0xAA55
#define DIR_ENTRY_SIZE 32


struct disk_t* disk_open_from_file(const char* volume_file_name){
    if(volume_file_name == NULL){perror("EFAULT"); return NULL; }

    // prepare space for disk handle
    struct disk_t* disc = (struct disk_t*)malloc(sizeof(struct disk_t));
    if(disc == NULL) { perror("ENOMEM"); return NULL; }

    //open disc file
    FILE* fp = fopen(volume_file_name,"rb");
    if(fp == NULL) {perror("ENOENT"); free(disc); return NULL;}

    //fill disc handle
    disc->d_pointer = fp;
    fseek(fp,11,SEEK_SET);
    fread(&(disc->bytes_per_sector),sizeof(uint16_t),1,fp);
    fseek(fp,0,SEEK_SET);

    return disc;

}
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read){
    if(pdisk == NULL || buffer == NULL){perror("EFAULT"); return -1;}

    //go to the sector user wants to read
    fseek(pdisk->d_pointer, first_sector * pdisk->bytes_per_sector, SEEK_SET);

    //read as many sectors as user wants to read
    int result = fread(buffer, pdisk->bytes_per_sector, sectors_to_read, pdisk->d_pointer);
    if(result != sectors_to_read){perror("ERANGE"); return -1;}

    return result;
}
int disk_close(struct disk_t* pdisk){
    if(pdisk == NULL){perror("EFAULT"); return -1;}
    fclose(pdisk->d_pointer);
    free(pdisk);
    return 0;
}
int validate_bootsector_1(struct volume_t* volume){
    if((volume->sectors_per_cluster != 1 && volume->sectors_per_cluster % 2 != 0) || volume->sectors_per_cluster < 1 || volume->sectors_per_cluster > 128) return 1;
//    if(volume->reserved_sectors < 0) return 2;  // sprawdzanie czy unsigned jest mniejszy od zera ?
    if(volume->fat_count != 1 && volume->fat_count != 2) return 3;
    if(volume->root_dir_capacity * sizeof(struct dir_entry_t) % volume->bytes_per_sector != 0) return 4;
    if(volume->logical_sectors32 == 0 ^ volume->logical_sectors16 != 0) return 5;
    if(volume->logical_sectors16 == 0 && volume->logical_sectors32 <= 65535) return 6;
    if(volume->magic != END_OF_BOOTSECTOR) return 7;
    return 0;
}
int validate_bootsector_2(struct volume_t* volume){

    // check if fat1 and fat2 are the same

    if(volume->fat_count == 1) return 0;
    uint8_t* pfat1 = (uint8_t*)malloc(volume->sectors_per_fat * volume->bytes_per_sector);
    uint8_t* pfat2 = (uint8_t*)malloc(volume->sectors_per_fat * volume->bytes_per_sector);
    if(pfat1 == NULL || pfat2 == NULL){ free(pfat1); free(pfat2); free(volume); perror("ENOMEM"); return 8;}
    int fat1_read = disk_read(volume->disk,volume->fat1_pos,pfat1,volume->sectors_per_fat);
    if(fat1_read == -1){ free(pfat1); free(pfat2); free(volume); return 9;}
    int fat2_read = disk_read(volume->disk,volume->fat2_pos,pfat2,volume->sectors_per_fat);
    if(fat2_read == -1){ free(pfat1); free(pfat2); free(volume); return 10;}
    if(memcmp(pfat1,pfat2,volume->sectors_per_fat * volume->bytes_per_sector) != 0){ free(pfat1); free(pfat2);perror("EINVAL"); return 11;}
    free(pfat1);
    free(pfat2);

    return 0;
}
void set_volume_additional_values(struct volume_t* volume, struct disk_t* pdisk){
    volume->disk = pdisk;
    volume->volume_start = 0;
    volume->fat1_pos = volume->volume_start + volume->reserved_sectors;
    volume->fat2_pos = volume->fat1_pos + volume->sectors_per_fat;
    volume->rootdir_pos = volume->fat1_pos + volume->fat_count * volume->sectors_per_fat;
    volume->rootdir_size = volume->root_dir_capacity * sizeof(struct dir_entry_t) / (int)(volume->bytes_per_sector);
    if((volume->root_dir_capacity * sizeof(struct dir_entry_t)) % volume->bytes_per_sector != 0 ) volume->rootdir_size += 1;
    volume->cluster2_pos = volume->rootdir_pos + volume->rootdir_size;
    uint32_t volume_size = volume->logical_sectors16 == 0 ? volume->logical_sectors32 : volume->logical_sectors16;
    uint32_t user_space = volume_size - volume->reserved_sectors - volume->fat_count * volume->sectors_per_fat - volume->rootdir_size;
    volume->total_clusters = user_space / volume->sectors_per_cluster;
}
struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector){

    // prepare space for bootsector
    struct volume_t* volume = (struct volume_t*)malloc(sizeof(struct volume_t));
    if(volume == NULL){perror("ENOMEM"); return NULL;}

    // read bootsector
    int returned = disk_read(pdisk,first_sector,volume,1);
    if(returned == -1) { free(volume); return NULL; }

    // check bootsector for problems and set additional geometry values ( 3 additional functions)
    volume->disk = pdisk;
    if(validate_bootsector_1(volume) != 0){ perror("EINVAL"); free(volume); return NULL; }
    set_volume_additional_values(volume,pdisk);
    if(validate_bootsector_2(volume) != 0){free(volume); return NULL; }

    // return happy and usefull bootsector
    return volume;
}
int fat_close(struct volume_t* pvolume){
    if(pvolume == NULL){perror("EFAULT"); return -1;}
    //jak zamknąć wolumin???? otwieramy tylko jeden plik w disk_read, mamy go tu zamknąć?
    free(pvolume);
    pvolume = NULL;
    return 0;
}
int file_names_match(struct dir_entry_t* entry, const char* file_name){
    char name[13];
    int counter = 0;
    for(;counter < 8; ++counter){
        if(entry->name[counter] == ' ') break;
        name[counter] = entry->name[counter];
    }
    name[counter] = '.';
    if(entry->name[8] == ' ') name[counter] = '\0';
    else{
        memcpy(name + counter + 1,entry->name + 8,3);
        name[counter+1+3] = '\0';
    }
    if(name[counter+1+2] == ' ') name[counter+1+2] = '\0';
    if(strcmp(name,file_name) == 0) return 1;
    else return 0;
}
uint16_t find_EOC(const uint8_t* fat_table){
    uint16_t EOC = 0;
    uint8_t left_byte = *((uint8_t*)fat_table + 1);
    uint8_t right_byte = *((uint8_t*)fat_table + 1 + 1);
    EOC += (uint16_t)right_byte << 4;
    EOC += (uint16_t)left_byte >> 4;
    return EOC;
}
void get_chain_fat12(struct file_t* file, const void * const buffer, uint16_t first_cluster, uint16_t EOC){

    file->clusters_count = 0;

    uint16_t next_cluster;
    file->clusters = (size_t*)malloc((file->clusters_count + 1) * sizeof(size_t));
    for(uint16_t cluster = first_cluster; cluster < 0xFF8/*cluster != EOC*/; cluster = next_cluster){

        size_t* temp = realloc(file->clusters,(file->clusters_count + 1) * sizeof(size_t));
        assert(temp != NULL);
        file->clusters = temp;

        file->clusters[file->clusters_count] = cluster;
        file->clusters_count++;

        next_cluster = 0;
        if(cluster % 2 == 0){
            cluster = cluster + cluster/2;
            uint8_t left_byte = *((uint8_t*)buffer + cluster); //*(uint8_t *)&cluster;
            uint8_t right_byte = *((uint8_t*)buffer + cluster + 1); //*((uint8_t*)&cluster) + 1;
            right_byte &= 0x0F;
            next_cluster |= (uint16_t)right_byte << 8;
            next_cluster |= (uint16_t)left_byte;
        }
        else {
            cluster = cluster + cluster/2;
            uint8_t left_byte = *((uint8_t*)buffer + cluster);
            uint8_t right_byte = *((uint8_t*)buffer + cluster + 1); //*((uint8_t*)&cluster) + 1;
            next_cluster |= (uint16_t)right_byte << 4;
            next_cluster |= (uint16_t)left_byte >> 4;
        }
    }
}
struct file_t* file_open(struct volume_t* pvolume, const char* file_name){
    // check if parameters are correct
    if(pvolume == NULL || file_name == NULL) {perror("EFAULT"); return NULL;}

    // prepare space for file handle/descriptor (file_t*)
    struct file_t* file_handle = (struct file_t*)malloc(sizeof(struct file_t));
    if(file_handle == NULL){ perror("ENOMEM"); return NULL; }

    // set some values of file handle
    file_handle->clusters_count = 0;
    file_handle->size_in_bytes = 0;
    file_handle->first_cluster = 0;
    file_handle->clusters = NULL;
    file_handle->position = 0;
    file_handle->volume = pvolume;

    // prepare space for main directory
    uint8_t* root_dir = (uint8_t*)malloc(pvolume->rootdir_size * pvolume->bytes_per_sector);
    if(root_dir == NULL){ perror("ENOMEM"); free(file_handle); return NULL; }

    // read main directory from disk
    int read_returned = disk_read(pvolume->disk,pvolume->rootdir_pos,root_dir, pvolume->rootdir_size);
    if(read_returned == -1){free(file_handle); free(root_dir); return NULL;}

    // prepare space for single directory entry
    struct dir_entry_t* entry = (struct dir_entry_t*)malloc(sizeof (struct dir_entry_t));
    assert(entry != NULL);

    // iterate through all directory entries
    int flag_found_file = 0;
    for(int i = 0; i < pvolume->root_dir_capacity; i++){

        // load entry from main directory
        memcpy(entry, root_dir + i * DIR_ENTRY_SIZE,32);

        // check if entry's name is the one we are looking for
        if(file_names_match(entry,file_name)){
            if(entry->attributes & FAT_ATTRIB_DIRECTORY || entry->attributes & FAT_ATTRIB_VOLUME){
                perror("EISDIR"); free(file_handle); free(entry); free(root_dir); return NULL;
            }
            else {
                flag_found_file = 1;
                break;
            }
        }
    }
    free(root_dir);


    // after finding / not finding file in main directory
    if(!flag_found_file){
        perror("ENOENT");free(entry); free(file_handle); return NULL;
    }

    else{  // creating file handle/descriptor of found file

        file_handle->size_in_bytes = entry->size;
        file_handle->first_cluster = entry->low_chain_index;


        // reading fat table
        uint8_t* fat1 = (uint8_t*)malloc(pvolume->sectors_per_fat * pvolume->bytes_per_sector);
        read_returned = disk_read(pvolume->disk, pvolume->fat1_pos, fat1, pvolume->sectors_per_fat);
        if(read_returned == -1) {free(file_handle); return NULL; }

        //finding EOC - EndOfChain
        uint16_t EOC = find_EOC(fat1);

        //filling file_handle with chain
        get_chain_fat12(file_handle, fat1, file_handle->first_cluster, EOC);
        free(fat1);


    }
    free(entry);
    return file_handle;
}
int file_close(struct file_t* stream){
    if(stream == NULL){perror("EFAULT");return -1;}
    if(stream->clusters != NULL) free(stream->clusters);
    free(stream);
    return 0;
}
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream){
    if(ptr == NULL || stream == NULL){perror("EFAULT"); return -1;} //wtf, why should it return in some tests xD

    size_t bytes_read = 0;
    int current_cluster_idx;
    int offset_from_cluster_start;
    int cluster_size = stream->volume->bytes_per_sector * stream->volume->sectors_per_cluster;
    uint8_t* cluster = (uint8_t*)malloc(cluster_size);
    assert(cluster != NULL);
    unsigned int remaining_chars_to_read = size * nmemb - bytes_read;
    if(remaining_chars_to_read > stream->size_in_bytes-stream->position) remaining_chars_to_read = stream->size_in_bytes - stream->position;


    while(1){
        current_cluster_idx = stream->position / cluster_size;
        if(current_cluster_idx > stream->clusters_count - 1){break;}
        offset_from_cluster_start = stream->position % cluster_size;

        if(cluster == NULL){perror("ENOMEM"); free(cluster); return -1;}
        int read_returned = disk_read(stream->volume->disk, stream->volume->cluster2_pos +
            (stream->clusters[current_cluster_idx] - 2) *
                stream->volume->sectors_per_cluster,cluster,stream->volume->sectors_per_cluster);
        if(read_returned == -1) {free(cluster); return -1; }

        unsigned int remaining_bytes_in_cluster = (cluster_size) - offset_from_cluster_start;
        int chars_to_read;
        if(remaining_chars_to_read >= remaining_bytes_in_cluster) chars_to_read = remaining_bytes_in_cluster;
        else {
            chars_to_read = remaining_chars_to_read;
            memcpy((uint8_t *)ptr + bytes_read, cluster + offset_from_cluster_start, chars_to_read);
            bytes_read +=chars_to_read;
            stream->position += chars_to_read;
            break;
        }

        memcpy((uint8_t *)ptr + bytes_read, cluster + offset_from_cluster_start, chars_to_read);
        bytes_read += chars_to_read;
        stream->position += chars_to_read;
        remaining_chars_to_read -= chars_to_read;

    }



    free(cluster);
    return bytes_read / size;
} ////////////xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
int32_t file_seek(struct file_t* stream, int32_t offset, int whence){
    if(stream == NULL) {perror("EFAULT"); return -1; }
    if(whence != SEEK_SET && whence != SEEK_CUR && whence != SEEK_END){perror("EINVAL"); return -1; }
    long long int starting_position;
    if(whence == SEEK_SET) starting_position = 0;
    if(whence == SEEK_CUR) starting_position = stream->position;
    if(whence == SEEK_END) starting_position = stream->size_in_bytes;

    long long int new_position = starting_position + offset;
    if(new_position < 0 || new_position > (int)(stream->size_in_bytes)-1){perror("ENXIO"); return -1; }
    stream->position = new_position;
    return 1;
}
struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path){
    if( pvolume == NULL || dir_path == NULL) { perror("EFAULT"); return NULL; }
    struct dir_t* directory = (struct dir_t*) malloc(sizeof(struct dir_t));
    if(directory == NULL){perror("ENOMEM"); return NULL;}
    if(strcmp(dir_path,"\\") != 0){perror("ENOENT"); free(directory); return NULL;}

    directory->pvolume = pvolume;
    directory->last_entry_idx = 0;

    return directory;
}
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry){
    if(pdir == NULL || pentry == NULL){perror("EFAULT"); return -1;}

    // prepare space for main directory
    uint8_t* root_dir = (uint8_t*)malloc(pdir->pvolume->rootdir_size * pdir->pvolume->bytes_per_sector);
    if(root_dir == NULL){ perror("ENOMEM"); ; return -1; }

    // read main directory from disk
    int read_returned = disk_read(pdir->pvolume->disk,pdir->pvolume->rootdir_pos,root_dir, pdir->pvolume->rootdir_size);
    if(read_returned == -1){; free(root_dir); return -1;}

    // prepare space for single directory entry
    struct dir_entry_t* entry = (struct dir_entry_t*)malloc(sizeof (struct dir_entry_t));
    assert(entry != NULL);

    // iterate through all directory entries
    for(int i = pdir->last_entry_idx; i < pdir->pvolume->root_dir_capacity; i++){

        // load entry from main directory
        memcpy(entry, root_dir + i * DIR_ENTRY_SIZE,32);
        if(*(entry->name) == 0x00) continue;
        else if(*(uint8_t*)(entry->name) == 0xE5) continue;
        else{

            memcpy(pentry,entry,32);
            pdir->last_entry_idx = i + 1;
            free(root_dir);

            int counter;
            for(counter = 0; counter < 8; counter++){
                if(*((pentry->name)+counter) == ' ') break;
            }
            *(pentry->name + counter) = '.';
            counter++;
            memcpy(pentry->name + counter,entry->name+8,3);
            if(*(pentry->name + counter) == ' ') *(pentry->name + counter - 1) = '\0';
            else *(pentry->name + counter + 3) = '\0';
            if(*(pentry->name + counter + 2) == ' ') *(pentry->name + counter + 2) = '\0';
            free(entry);
            return 0;
        }
    }
    free(root_dir);
    free(entry);


    return 1;
}
int dir_close(struct dir_t* pdir){
    if(pdir == NULL){perror("EFAULT"); return -1;}
    free(pdir);
    return 0;
}
