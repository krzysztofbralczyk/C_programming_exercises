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