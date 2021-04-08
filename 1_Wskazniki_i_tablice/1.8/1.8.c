#include <stdio.h>
#include "vector_utils.h"
// #include "vector_utils.c"

int sort(int* tab, int size);

int main(){
    printf("Podaj liczby: ");
    int numbers[100];
    int vector_length = read_vector(numbers,100,-1);
    if(vector_length == 0){
        printf("Not enough data available");
        return 3;
    } else if(vector_length == -2){
        printf("Incorrect input");
        return 1;
    }
    sort(numbers,vector_length);
    display_vector(numbers,vector_length);
    return 0;
}

int sort(int* tab, int size){
    if(size<1 || !tab) return 1;

    for(int not_sorted = 1; not_sorted;){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(*(tab+i) > *(tab+i+1)){
                int temp = *(tab+i);
                *(tab+i) = *(tab+i+1);
                *(tab+i+1) = temp;
                not_sorted = 1;
            }
        }
    }
    return 0;
}