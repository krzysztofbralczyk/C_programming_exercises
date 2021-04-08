#include <stdio.h>
#include <string.h>
int load_data(struct message_t *cp, int size, const char *filename);
int decode_message(const struct message_t *cp, int size, char *msg, int text_size);
struct message_t
{
    char a;
    double b;
    int c;
};

void chomp(char* s) {
    while (*s && *s != '\n') s++;
    *s = '\0';
}

int main(){
    struct message_t structures[100];
    char filename[31];
    char msg[1100];
    printf("Enter file name: ");
    fgets(filename,31,stdin);
    chomp(filename);
    int load_returned = load_data(structures,100,filename);
    if(load_returned == -2){
        printf("Couldn't open file");
        return 4;
    } else if(load_returned == -3){
        printf("File corrupted");
        return 6;
    }
    decode_message(structures,load_returned,msg,1101);
    printf("%s",msg);

    return 0;
}

int load_data(struct message_t *cp, int size, const char *filename){
    if(cp == NULL || size <= 0 || filename == NULL) return -1;
    FILE* fp = fopen(filename,"r");
    if(fp == NULL) return -2;

    int size_of_all_structures = 1;
    int read_result = fread(&size_of_all_structures,sizeof(int),1,fp); //fread zwraca ilosc elementow poprawnie odczytanych
    // wiec jesli poprawnie odczytal tego cholernego inta, zwroci jeden. Jesli sie nie udalo bo naprzyklad byl char'em, 
    // zwroci zero a plik is corrupted. Dodatkowo ten int ma chyba reprezentowac sumaryczna wielkosc struktur ktore po nim nastapia. wiec ten int musi
    // byc wielokrotnoscia wielkosci jednej struktury, inaczej plik is corrupted
    if(read_result != 1 || size_of_all_structures % sizeof(struct message_t) != 0){
        fclose(fp);
        return -3;
    }
    int amount_of_structures = size_of_all_structures/sizeof(struct message_t);

    if(amount_of_structures > size) amount_of_structures = size;

    read_result = fread(cp, sizeof(struct message_t),amount_of_structures,fp);
    if(read_result != amount_of_structures){
        fclose(fp);
        return -3;
    }
    fclose(fp);
    return amount_of_structures;




}

int decode_message(const struct message_t *cp, int size, char *msg, int text_size){
    if(cp == NULL || msg == NULL || size <= 0 || text_size <= 0) return 1;
    *msg = '\0';
    if(text_size == 1){
        strcpy(msg,"");
        return 0;
    }
        
    for(int i = 0; i < size; i++){
        char* pointer_to_struct_casted_to_bytes = (char*)(cp+i);

        int free_space_after_char = sizeof(double) - sizeof(char);
        int free_space_after_int = sizeof(double) - sizeof(int);

        if( (i+1) * (free_space_after_char + free_space_after_int) < text_size-1){

            strncat(msg, pointer_to_struct_casted_to_bytes + sizeof(char), free_space_after_char);
            strncat(msg, pointer_to_struct_casted_to_bytes + 2 * sizeof(double) + sizeof(int), free_space_after_int);

        } else if ( (i+1) * (free_space_after_char + free_space_after_int) - free_space_after_int < text_size-1) {
            strncat(msg, pointer_to_struct_casted_to_bytes + sizeof(char), free_space_after_char);
            // xxxxxxxxxxxxxxxxxx
            strncat(msg,pointer_to_struct_casted_to_bytes + 2 * sizeof(double) + sizeof(int), text_size - 1 - (i+1) * (free_space_after_char + free_space_after_int) + free_space_after_int);
        } else {
            //xxxxxxxxxxx
            strncat(msg, pointer_to_struct_casted_to_bytes + sizeof(char), text_size - 1 - (i) * (free_space_after_char + free_space_after_int));
        }
        
    }

    return 0;
}