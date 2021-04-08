#ifndef FILE_READER_H
#define FILE_READER_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

//typedef struct bytes3_t {
//    uint8_t b0;
//    uint8_t b1;
//    uint8_t b2;
//}bytes3_t;
//
//typedef struct short2_t {
//    uint16_t c1:12;
//    uint16_t c2:12;
//}__attribute__ ((packed))short2_t;
//
//typedef union map_t {
//    bytes3_t bytes3;
//    short2_t short2;
//}map_t;

struct disk_t{
    FILE* d_pointer;
    uint16_t bytes_per_sector;
} __attribute__ ((packed));
struct volume_t{

    //main part, 512 bytes
    uint8_t jump_code[3];
    char oem_name[8];
    uint16_t bytes_per_sector;
    uint8_t sectors_per_cluster;
    uint16_t reserved_sectors;
    uint8_t fat_count;
    uint16_t root_dir_capacity;
    uint16_t logical_sectors16;
    uint8_t media_type;
    uint16_t sectors_per_fat;
    uint16_t chs_sectors_per_track;
    uint16_t chs_tracks_per_cylinder;
    uint32_t hidden_sectors;
    uint32_t logical_sectors32;
    uint8_t media_id;
    uint8_t chs_head;
    uint8_t ext_bpb_signature;
    uint32_t serial_number;
    char volume_label[11];
    char fsid[8];
    uint8_t boot_code[448];
    uint16_t magic;

    //additions
    struct disk_t* disk;
    uint32_t volume_start;
    uint32_t fat1_pos;
    uint32_t fat2_pos;
    uint32_t rootdir_pos;
    uint32_t rootdir_size;
    uint32_t cluster2_pos;
    uint32_t total_clusters;
} __attribute__ ((packed));
struct file_t{
    size_t *clusters;
    uint16_t clusters_count;
    uint32_t first_cluster;
    size_t size_in_bytes;
    size_t position;
    struct volume_t* volume;

};
struct dir_t{
    struct volume_t* pvolume;
    size_t last_entry_idx;
};
typedef uint16_t fat_date_t;
typedef uint16_t fat_time_t;
enum fat_attributes_t {
    FAT_ATTRIB_READONLY = 0x01,
    FAT_ATTRIB_HIDDEN = 0x02,
    FAT_ATTRIB_SYSTEM = 0x04,
    FAT_ATTRIB_VOLUME = 0x08,
    FAT_ATTRIB_DIRECTORY = 0x10,
    FAT_ATTRIB_ARCHIVED = 0x20
} __attribute__ ((packed));
struct  dir_entry_t {
    char name[8 + 3];                   //0 - 10
    enum fat_attributes_t attributes;   //11
    uint8_t __reserved0;                //12
    uint8_t creation_time_ms;           //13
    fat_time_t creation_time;           //14-15
    fat_date_t creation_date;           //16-17
    fat_time_t last_access_time;        //18-19
    uint16_t high_chain_index;          //20-21
    fat_time_t last_modification_time;  //22-23
    fat_date_t last_modification_date;  //24-25
    uint16_t low_chain_index;           //26-27
    uint32_t size;                      //28-31
} __attribute__ ((packed));

struct disk_t* disk_open_from_file(const char* volume_file_name);
int disk_read(struct disk_t* pdisk, int32_t first_sector, void* buffer, int32_t sectors_to_read);
int disk_close(struct disk_t* pdisk);

struct volume_t* fat_open(struct disk_t* pdisk, uint32_t first_sector);
int fat_close(struct volume_t* pvolume);

struct file_t* file_open(struct volume_t* pvolume, const char* file_name);
int file_close(struct file_t* stream);
size_t file_read(void *ptr, size_t size, size_t nmemb, struct file_t *stream);
int32_t file_seek(struct file_t* stream, int32_t offset, int whence);

struct dir_t* dir_open(struct volume_t* pvolume, const char* dir_path);
int dir_read(struct dir_t* pdir, struct dir_entry_t* pentry);
int dir_close(struct dir_t* pdir);


#endif
