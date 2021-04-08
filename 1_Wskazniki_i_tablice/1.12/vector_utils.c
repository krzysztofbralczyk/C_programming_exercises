#include "vector_utils.h"

int read_vector_float(float *vec, int size, float stop_value){
    if(!vec || size <= 0) return -1;

    int ele_counter = 0;
    float number;

    if(!scanf("%f",&number)) return -2;
    while (ele_counter < size && number != stop_value){
        *(vec+ele_counter) = number;
        ele_counter++;
        if(!scanf("%f",&number)) return -2;
    }
    
    return ele_counter;
}

void display_vector(const int* tab, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",*(tab + i));
    }
}

int create_histogram(const float *vec, int size, int *out, int out_size){
    if(vec == NULL || size < 1 || out == NULL || out_size < 1) return 1;

    //**START** - zerowanie wyjsciowej tabeli 
    for(int i = 0; i < out_size; i++){
        *(out+i) = 0;
    }
    //**END**

    for(int i = 0; i < size; i++){
        for(int j = 1; j <= out_size; j++){
            if(*(vec+i) < 0) break;
            if(*(vec+i) < j){
                *(out+j-1) += 1;
                break;
            }
        }
    }

    return 0;
}