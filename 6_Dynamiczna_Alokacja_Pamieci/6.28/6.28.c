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
int statistics(int** ptr, struct statistic_t** stats);
void display(int** ptr);
int save(const char* filename, int** ptr, enum save_format_t format);



int main() {
    int A[] = { 10, 20, 30, 40, 50, 60, 70, -1 };
    int B[] = { 100, 200, 300, 400, 500, 600, 700, 800, -1 };
    int C[] = { 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, -1 };
    int* D[] = { A, B, C, NULL };

    display(D);

    char* filename = (char*)malloc(40 * sizeof(char));
    if (filename == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj nazwe pliku: ");
    scanf("%39s", filename);

    char* filename_txt = (char*)malloc(39 * sizeof(char));
    
    if (filename_txt == NULL) {
        printf("Failed to allocate memory");
        free(filename);
        return 8;
    }
    char* new_filename_txt = (char*)realloc(filename_txt,44 * sizeof(char));
    if(new_filename_txt == NULL){
        printf("Failed to allocate memory");
        free(filename);
        return 8;
    } else {
        filename_txt = new_filename_txt;
    }
    strcpy(filename_txt, filename);
    strcat(filename_txt, ".txt");

    char* filename_bin = (char*)malloc(39 * sizeof(char));
    if (filename_bin == NULL) {
        printf("Failed to allocate memory");
        free(filename);
        free(filename_txt);
        return 8;
    }
    char* new_filename_bin = (char*)realloc(filename_bin,44 * sizeof(char));
    if(new_filename_bin == NULL){
        printf("Failed to allocate memory");
        free(filename);
        free(filename_txt);
        return 8;
    } else {
        filename_bin = new_filename_bin;
    }
    strcpy(filename_bin, filename);
    strcat(filename_bin, ".bin");

    if (save(filename_txt, D, fmt_text) == 2) {
        printf("Couldn't create file\n");
    }
    else {
        printf("File saved\n");
    }
    if (save(filename_bin, D, fmt_binary) == 2) {
        printf("Couldn't create file\n");
    }
    else {
        printf("File saved\n");
    }
    struct statistic_t* stats_str_pt;
    struct statistic_t** stats_str_pt_to_pt = &stats_str_pt;
    if (statistics(D,stats_str_pt_to_pt) == 2) {
        printf("Failed to allocate memory");
        free(filename);
        free(filename_bin);
        free(filename_txt);
        return 8;
    }
    printf("%d\n%d\n%d\n%f\n%f", stats_str_pt->min, stats_str_pt->max, stats_str_pt->range, stats_str_pt->avg, stats_str_pt->standard_deviation);
    free(filename);
    free(filename_bin);
    free(filename_txt);
    free(stats_str_pt);

    return 0;
}

int statistics(int** ptr, struct statistic_t** stats) {
    if (ptr == NULL || stats == NULL) return 1;
    *stats = (struct statistic_t*)malloc(sizeof(struct statistic_t));
    if (*stats == NULL) return 2;
    if (*ptr == NULL){ 
        free(*stats);
        return 3; 
    } 
    int min = **ptr;
    int max = **ptr;
    int sum = 0;
    int counter = 0;
    int sum_of_squares = 0;

    for (int i = 0; *(ptr + i) != NULL; i++) {
        for (int j = 0; *(*(ptr + i) + j) != -1; j++) {
            if (*(*(ptr + i) + j) < min) min = *(*(ptr + i) + j);
            if (*(*(ptr + i) + j) > max) max = *(*(ptr + i) + j);
            sum += *(*(ptr + i) + j);
            sum_of_squares += (int)pow(*(*(ptr + i) + j), 2);
            counter++;
        }
    }
    if (counter == 0){
        free(*stats);
        return 3; 
    } 
    float average = (float)sum / counter;
    float standard_deviation = sqrt((float)sum_of_squares / counter - pow(average, 2));
    (*stats)->min = min;
    (*stats)->max = max;
    (*stats)->avg = average;
    (*stats)->range = max - min;
    (*stats)->standard_deviation = standard_deviation;

    return 0;
}
void display(int** ptr) {
    if (ptr == NULL) return;
    for (int i = 0; *(ptr + i) != NULL; i++) {
        for (int j = 0; *(*(ptr + i) + j) != -1; j++) {
            printf("%d ", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}
int save(const char* filename, int** ptr, enum save_format_t format) {
    if (filename == NULL || ptr == NULL || (format != 1 && format != 2)) return 1;

    if (format == fmt_text) {
        FILE* fp = fopen(filename, "w");
        if (fp == NULL) return 2;

        for (int i = 0; *(ptr + i) != NULL; i++) {
            for (int j = 0; *(*(ptr + i) + j) != -1; j++) {
                fprintf(fp, "%d ", *(*(ptr + i) + j));
            }
            fprintf(fp, "-1 \n");
        }

        fclose(fp);
    }
    if (format == fmt_binary) {
        FILE* fp = fopen(filename, "wb");
        if (fp == NULL) return 2;

        // for (int i = 0; *(ptr + i) != NULL; i++) {
        //     fwrite(*(ptr + i), sizeof(int), 8 + i, fp);
        // }
         for (int i = 0; *(ptr + i) != NULL; i++) {
            int j = 0;
            for (; *(*(ptr + i) + j) != -1; j++) fwrite((*(ptr+i)+j),sizeof(int),1,fp);
            fwrite((*(ptr+i)+j),sizeof(int),1,fp);
        }

        fclose(fp);
    }

    return 0;
}