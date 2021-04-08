#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "format_type.h"

struct statistic_t
{
  int min;
  int max;
  float avg;
  float standard_deviation;
  int range;
};

int load(const char *filename, int ***ptr, enum save_format_t format);
int load_txt(const char *filename, int ***ptr);
int arr_len(FILE *fp, enum save_format_t format);
int load_bin(const char *filename, int ***ptr);
int statistics_row(int **ptr, struct statistic_t **stats);
void destroy(int ***ptr);
void display(int **ptr);

int main(){
    
    char* filename = (char*)malloc(40*sizeof(char));
    if(filename == NULL){printf("Failed to allocate memory"); return 8; }
    printf("Nazwa pliku: ");
    
    scanf("%39s",filename);

    char* format = filename + strlen(filename) - 4;

    int load_returned;
    int** pointers_array = NULL;
    if(strcmp(format,".txt") == 0)load_returned = load(filename,&pointers_array,fmt_text);
    else if(strcmp(format,".bin") == 0)load_returned = load(filename,&pointers_array,fmt_binary);
    else {printf("Unsupported file format"); free(filename); return 7; }

    if(load_returned == 2){printf("Couldn't open file"); free(filename); return 4;}
    else if(load_returned == 3){printf("File corrupted"); free(filename); return 6;}
    else if(load_returned == 4){printf("Failed to allocate memory"); free(filename); return 8;}

    struct statistic_t* stats = NULL;
    int statistics_returned = statistics_row(pointers_array,&stats);
    if(statistics_returned == -2){printf("Failed to allocate memory"); free(filename); destroy(&pointers_array); return 8;}

    //test!
    for(int i = 0; i < statistics_returned; i++) printf("%d %d %d %f %f\n",(stats+i)->min,(stats+i)->max,(stats+i)->range,(stats+i)->avg,(stats+i)->standard_deviation);
    //test!
    display(NULL);
    
    free(filename);
    destroy(&pointers_array);
    free(stats);
    return 0;
}
int load(const char *filename, int ***ptr, enum save_format_t format){
    if(filename == NULL || ptr == NULL || (format!=1 && format !=2)) return 1;
    int load_result = 99999;
    if(format == fmt_text) load_result = load_txt(filename,ptr);
    else load_result = load_bin(filename,ptr);
    
    return load_result; 
}
int load_txt(const char *filename, int ***ptr){
    FILE* fp = fopen(filename,"r");
    if(fp == NULL) return 2;


    //START-- rows counting and allocation --START
    int fscanf_returned, number = -1, rows_counter = 0;

    while(!feof(fp)){
        fscanf_returned = fscanf(fp,"%d",&number);
        if(fscanf_returned != 1 && !feof(fp)){ fclose(fp); return 3;}
        else if(rows_counter == 0 && feof(fp)) {fclose(fp); return 3;}
        if(number == -1) rows_counter++;
        number = 0;
    }


    int **pointers_array=(int**)malloc((rows_counter+1)*sizeof(int*));
    if(pointers_array == NULL){
        fclose(fp);
        return 4;
    }

    fseek(fp,0,SEEK_SET);
    //END-- rows counting and allocation --END


    //START-- elements per row counting and allocation --START
    int current_row = 0, current_column = 0;
    while(!feof(fp)){
        if(current_column == 0){ //if at the beggining of the row, count row elements and allocate memory for them

            int array_length = arr_len(fp,fmt_text); //if arr_len_txt couldn't read number, file pointer won't be rewind, so if it hit eof, it will still point to eof
            if (feof(fp)) break;
            if(array_length < 0) { // arr_len_txt returns -1 if it couldn't read number
                fclose(fp);
                for(int i = 0; i < current_row; i++) free(*(pointers_array+i));
                free(pointers_array);
                return 3; //file corrupted
            }
            *(pointers_array+current_row)=(int*)malloc(array_length*sizeof(int));

            if(*(pointers_array+current_row) == NULL){
                fclose(fp);
                for(int i = 0; i < current_row; i++) free(*(pointers_array+i));
                free(pointers_array); 
                return 4; // couldn't allocate memory
            }
        }

        fscanf_returned = fscanf(fp, "%d", &number);
        if(fscanf_returned != 1 && !feof(fp)){
            fclose(fp);
            for(int i = 0; i < current_row; i++) free(*(pointers_array+i));
            free(pointers_array);
            return 3; //file corrupted
        }
        *(*(pointers_array+current_row)+current_column) = number;
        current_column++;

        if(number == -1) {
            current_row++;
            current_column=0;
        }
        
    }

    *(pointers_array+current_row) = NULL;
    *ptr = pointers_array;
    //END-- elements per row counting and allocation --END

  fclose(fp);
  return 0;
}
int load_bin(const char *filename, int ***ptr){
    FILE* fp = fopen(filename,"rb");
    if(fp == NULL) return 2;

    //START-- rows counting and allocation --START
    int fread_returned, number = 0, rows_counter = 0;
    //test!
    // int test_counter = 0;
    //test!
    while(!feof(fp)){
        fread_returned = fread(&number, sizeof(int), 1, fp);
        if(fread_returned != 1 && !feof(fp)) {fclose(fp); return 3;}
        else if(rows_counter == 0 && feof(fp)) {fclose(fp); return 3;}
        if(number == -1) rows_counter++;
        number = 0;
    }

    int **pointers_array = (int**)malloc((rows_counter+1)*sizeof(int*));

    int test_counter=rows_counter*sizeof(int*);

    // printf("Zaalokowałem pamięc na %d wskaźników (int*) o wadze %lu, w sumie %lu bajtów | podsumowanie: %d bajtów\n",rows_counter,sizeof(int*),rows_counter*sizeof(int*),test_counter);


    if(pointers_array == NULL){
        fclose(fp);
        return 4;
    }

    fseek(fp,0,SEEK_SET);
    //END-- rows counting and allocation --END


    //START-- elements per row counting and allocation --START
    int current_row = 0, current_column = 0, array_length = -10;
    while(!feof(fp)){
        if(current_column == 0){ //if at the beggining of the row, count row elements and allocate memory for them
            array_length = arr_len(fp,fmt_binary); //if arr_len_txt couldn't read number, file pointer won't be rewind, so if it hit eof, it will still point to eof

            if (feof(fp)) break;

            if(array_length < 0) { // arr_len_txt returns -1 if it couldn't read number
                fclose(fp);
                for(int i = 0; i < current_row; i++) free(*(pointers_array+i));
                free(pointers_array);
                return 3; //file corrupted
            }

            *(pointers_array+current_row)=(int*)malloc(array_length*sizeof(int));
            test_counter+= array_length*sizeof(int);
            // printf("Zaalokowałem pamięc na %d intów o wadze %lu, w sumie %lu bajtów | podsumowanie: %d bajtów\n",array_length,sizeof(int),array_length*sizeof(int),test_counter);

            if(*(pointers_array+current_row) == NULL){
                fclose(fp);
                for(int i = 0; i < current_row; i++) free(*(pointers_array+i));
                free(pointers_array); 
                return 4; // couldn't allocate memory
            }
        }

        fread_returned = fread(&number, sizeof(int), 1, fp);
        if(fread_returned != 1 && !feof(fp)){
            fclose(fp);
            for(int i = 0; i < current_row; i++) free(*(pointers_array+i));
            free(pointers_array);
            return 3; //file corrupted
        }
        *(*(pointers_array+current_row)+current_column) = number;
        current_column++;

        if(number == -1) {
            current_row++;
            current_column=0;
        }
    }

    *(pointers_array+current_row) = NULL;
    *ptr = pointers_array;
    //END-- elements per row counting and allocation --END

  fclose(fp);
  return 0;
}
int statistics_row(int **ptr, struct statistic_t **stats){
    if(ptr == NULL || stats == NULL) return -1;
    int row_counter = 0;
    while(*(ptr + row_counter) != NULL) row_counter++;
    *stats = (struct statistic_t*)malloc(row_counter*sizeof(struct statistic_t));
    if (*stats == NULL) return -2;

    for(int i = 0; *(ptr+i) != NULL; i++){
        int min = **(ptr+i);
        int max = **(ptr+i);
        int sum = 0;
        int counter = 0;
        int sum_of_squares = 0;
        for(int j = 0; *(*(ptr+i)+j) != -1; j++){
            if (*(*(ptr + i) + j) < min) min = *(*(ptr + i) + j);
            if (*(*(ptr + i) + j) > max) max = *(*(ptr + i) + j);
            sum += *(*(ptr + i) + j);
            sum_of_squares += (int)pow(*(*(ptr + i) + j), 2);
            counter++;
        }
        if (counter == 0){
            (*stats+i)->min = -1;
            (*stats+i)->max = -1;
            (*stats+i)->avg = -1;
            (*stats+i)->range = -1;
            (*stats+i)->standard_deviation = -1;
        } else {
            float average = (float)sum / counter;
            float standard_deviation = sqrt((float)sum_of_squares / counter - pow(average, 2));
            (*stats+i)->min = min;
            (*stats+i)->max = max;
            (*stats+i)->avg = average;
            (*stats+i)->range = max - min;
            (*stats+i)->standard_deviation = standard_deviation;
        } 
    }

    return row_counter;
}
void destroy(int ***ptr){
    if(ptr == NULL) return;
    for(int i = 0; *(*ptr+i) != NULL; i++) free(*(*ptr+i));
    free(*ptr);
    *ptr = NULL;
}
void display(int **ptr){
    if (ptr == NULL) return;
    for (int i = 0; *(ptr + i) != NULL; i++) {
        for (int j = 0; *(*(ptr + i) + j) != -1; j++) {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}
int arr_len(FILE *fp, enum save_format_t format){
    long int initial_position = ftell(fp);
    int fscanread_returned, number = 0, i = 0;

    if(format == fmt_text) fscanread_returned = fscanf(fp,"%d",&number);
    else fscanread_returned = fread(&number,sizeof(int),1,fp);
    // printf("Allocated space for num: |%d|\n",number);
    if(fscanread_returned != 1) return -1;
    i++;

    while(number != -1){
        if(format == fmt_text) fscanread_returned = fscanf(fp,"%d",&number);
        else fscanread_returned = fread(&number,sizeof(int),1,fp);
        // printf("Allocated space for num: |%d|\n",number);
        if(fscanread_returned != 1) return -1;
        i++;
    }

  fseek(fp, initial_position, SEEK_SET);

  return i;
}