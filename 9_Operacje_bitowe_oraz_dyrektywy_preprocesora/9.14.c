#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


CREATE_READ_FUNCTIONS(int,"%d")
CREATE_SORT_FUNCTIONS(int)
CREATE_DISPLAY_FUNCTIONS(int,%d)
CREATE_READ_FUNCTIONS(float,"%f")
CREATE_SORT_FUNCTIONS(float)
CREATE_DISPLAY_FUNCTIONS(float,%f)
CREATE_READ_FUNCTIONS(double,"%lf")
CREATE_SORT_FUNCTIONS(double)
CREATE_DISPLAY_FUNCTIONS(double,%lf)

int main(){
    printf("Choose your type: ");
    int type;
    if(!scanf("%d",&type)){
        printf("Incorrect input");
        return 1;
    }
    if(type < 0 || type > 2){
        printf("Incorrect input data");
        return 2;
    }

    printf("Choose array size: ");
    int size;
    if(!scanf("%d",&size)){
        printf("Incorrect input");
        return 1;
    }
    if(size <= 0){
        printf("Incorrect input data");
        return 2;
    }

    if(type == 0){
        int* array = (int*)malloc(size * sizeof(int));
        if(array == NULL){
            printf("Failed to allocate memory");
            return 8;
        }
        int read_returned = read_int(array,size);
        if(read_returned == 1){
            free(array);
            printf("Incorrect input");
            return 1;
        }
        sort_int(array,size);
        display_int(array,size);
        free(array);
    }
    if(type == 1){
        float* array = (float*)malloc(size * sizeof(float));
        if(array == NULL){
            printf("Failed to allocate memory");
            return 8;
        }
        int read_returned = read_float(array,size);
        if(read_returned == 1){
            free(array);
            printf("Incorrect input");
            return 1;
        }
        sort_float(array,size);
        display_float(array,size);
        free(array);
    }
    if(type == 2){
        double* array = (double*)malloc(size * sizeof(double));
        if(array == NULL){
            printf("Failed to allocate memory");
            return 8;
        }
        int read_returned = read_double(array,size);
        if(read_returned == 1){
            free(array);
            printf("Incorrect input");
            return 1;
        }
        sort_double(array,size);
        display_double(array,size);
        free(array);
    }
    
    return 0;
}