#include <stdio.h>
#include "array.h"
// #include "array.c"

int main(){

    printf("Jak duza tablica?: ");
    int size;
    if(!scanf("%d",&size)){
        printf("Incorrect input");
        return 1;
    }
    if(size < 1){
        printf("Incorrect input data");
        return 2;
    }

    struct array_t own_array, *pown_array;
    pown_array = &own_array;

    int array_creation_returned = array_create(pown_array,size);
    if(array_creation_returned == 2){
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj liczby: ");
    int num = 1,full = 0;
    for(int i = 0; num != 0; i++){
        if(!scanf("%d",&num)){
            printf("Incorrect input");
            array_destroy(pown_array);
            return 1;
        }
        if(i >= size){
            full = 1;
            break;
        }
        if(num!=0)array_push_back(pown_array,num);
    }
    while(getchar()!= '\n');
    if(full)printf("Buffer is full\n");
    if(own_array.size == 0)printf("Buffer is empty");
    array_display(pown_array);
    array_destroy(pown_array);
    return 0;
}

