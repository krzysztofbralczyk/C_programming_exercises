#include "vector_utils.h"

int read_vector(int* tab, int size, int stop_value){
    if(!tab || size <= 0) return -1;

    int ele_counter = 0;
    int number;

    if(!scanf("%d",&number)) return -2;
    while (ele_counter < size && number != stop_value){
        *(tab+ele_counter) = number;
        ele_counter++;
        if(!scanf("%d",&number)) return -2;
    }
    
    return ele_counter;
}

void display_vector(const int* tab, int size){
    for(int i = 0; i < size; i++){
        printf("%d ",*(tab + i));
    }
}

int shift(int *array, int array_size, int positions_to_shift, enum direction dir){
    if(array == NULL || array_size < 1 || positions_to_shift < 0 || (dir != ROTATE_RIGHT && dir != ROTATE_LEFT)){ return 1; }

    if(dir == ROTATE_RIGHT){

        for(int times = 0; times < positions_to_shift; times++){

            int temp = *(array + array_size-1); 
            for(int i = array_size-1; i >= 0; i--){ *(array + i + 1) = *(array + i); }
            *(array) = temp;

        }
        
    }else if (dir == ROTATE_LEFT){

        for(int times = 0; times < positions_to_shift; times++){

            int temp = *(array);
            for(int i = 0; i < array_size - 1; i++){ *(array + i) = *(array + i + 1); }
            *(array + array_size - 1) = temp;

        }
        
    }
    
    return 0;
}