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

    struct array_t src_array, *ptsrc_array, odd_array, *ptodd_array, even_array, *pteven_array;
    ptsrc_array = &src_array;
    ptodd_array = &odd_array;
    pteven_array = &even_array;

    int array_creation_returned = array_create(ptsrc_array,size);
    if(array_creation_returned == 2){
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj liczby: ");
    int num = 1;
    int full = 0;
    for(int i = 0; num != 0; i++){
        if(!scanf("%d",&num)){
            printf("Incorrect input");
            array_destroy(ptsrc_array);
            return 1;
        }

        if(i == 0 && num == 0){
            printf("Not enough data available");
            array_destroy(ptsrc_array);
            return 3;
        }

        if(i == size){
            full = 1;
        }
        if(i > size) full++;
        if(num!=0 && !full) array_push_back(ptsrc_array,num);
    }
    while(getchar()!= '\n');

    
    int separate_returned = array_separate(ptsrc_array,ptodd_array,pteven_array);
    if(separate_returned == 0){
        printf("Failed to allocate memory");
        array_destroy(ptsrc_array);
        return 8;
    }

    if(full>1)printf("Buffer is full\n");
    // if(src_array.size == 0)printf("Buffer is empty\n");
    // array_display(ptsrc_array);
    // printf("\n");
    
    if(separate_returned == 1){
        array_display(ptodd_array);
        printf("\nBuffer is empty");
    } else if(separate_returned == 2){
        printf("Buffer is empty\n");
        array_display(pteven_array);
    } else if(separate_returned == 3){
        array_display(ptodd_array);
        printf("\n");
        array_display(pteven_array);
    }

    array_destroy(pteven_array);
    array_destroy(ptodd_array);
    array_destroy(ptsrc_array);
    return 0;
}

