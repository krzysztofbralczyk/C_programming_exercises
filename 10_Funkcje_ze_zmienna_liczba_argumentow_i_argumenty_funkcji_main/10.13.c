#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>


int* count_words(const char *filename, int *err_code, int N, ...);

int main(int argc, char *argv[]){
    if(argc < 3){printf("Not enough arguments"); return 9;}
    int error_code;
    for(int i = 0; i < argc-2; i++){
        int* counters = count_words(*(argv+1), &error_code, 1, *(argv+i+2));
        if(error_code == 2){printf("Couldn't open file"); return 4;}
        else if(error_code == 3){printf("Failed to allocate memory"); return 8;}
        printf("%d\n",*counters);
        free(counters);
    }
    
    return 0;
}

int* count_words(const char *filename, int *err_code, int N, ...){
    if(filename == NULL || N<=0){ if(err_code!= NULL) *err_code = 1; return NULL;} 
    
    FILE* fp = fopen(filename,"r");
    if(fp == NULL){ if(err_code!= NULL) *err_code = 2; return NULL;}
    int *counts = (int*)malloc(N*sizeof(int));
    if(counts == NULL){fclose(fp); if(err_code!= NULL) *err_code = 3; return NULL;}
    for(int i = 0; i < N; i++) *(counts+i) = 0;
    va_list args;
    va_start(args,N);

    char* word;
    for(int i = 0; i < N; i++){
        fseek(fp,0,SEEK_SET);
        word = va_arg(args, char*);
        char previous = '\0';
        for(char temp_char = fgetc(fp); !feof(fp); temp_char = fgetc(fp)){
            if(temp_char == *word){
                long int pos = ftell(fp);
                int found_word = 1;
                if(previous != ' ' && previous != '\0' && previous != '\n' && previous != '\'' && previous != '"') found_word = 0;
                for(unsigned int j = 1; j < strlen(word) && !feof(fp); j++){ if(fgetc(fp) != *(word+j)) found_word = 0; }
                char temp;
                temp = fgetc(fp);
                if(temp != ' ' && temp != '.' && temp != '\n' && temp != '\0' && temp != '\'' && temp != ',' && temp != '?') found_word = 0;
                fseek(fp,pos,SEEK_SET);
                if(found_word) (*(counts+i))++;
            }
            previous = temp_char;
        }
    }
    
    va_end(args);
    fclose(fp);
    if(err_code != NULL)*err_code = 0;
    return counts;
}