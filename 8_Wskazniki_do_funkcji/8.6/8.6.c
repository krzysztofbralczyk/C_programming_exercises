#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
// #include "comparators.c"

// funkcja zwracająca wskaźnik do funkcji           int (*get_function(enum operations_t operation))(int, int);
// funkcja wykorzystująca wskaźnik do funkcji       int calculate(int num1, int num2, int(*function)(int, int));

int main(){

    typedef int (*functype)(int, int);
    functype* comparators = malloc(4 * sizeof(functype));
    if(comparators == NULL){
        printf("Failed to allocate memory");
        return 8;
    }

    *comparators = comp_int;
    *(comparators+1) = comp_int_abs;
    *(comparators+2) = comp_int_length;
    *(comparators+3) = comp_int_digits_sum;

    printf("How many numbers?: ");
    int size;
    if(!scanf("%d", &size)){
        printf("Incorrect input");
        free(comparators);
        return 1;
    }
    if(size <= 0){
        printf("Incorrect input data");
        free(comparators);
        return 2;
    }
    int* numbers = (int*)malloc(size * sizeof(int));
    if( numbers == NULL){
        printf("Failed to allocate memory");
        free(comparators);
        return 8;
    }
    printf("Podaj liczby: ");
    for(int i = 0; i < size; i++){
        if(!scanf("%d", numbers+i)){
            printf("Incorrect input");
            free(comparators);
            free(numbers);
            return 1;
        }
    }

    printf("Type of operation please: ");
    int operator;
    if(!scanf("%d",&operator)){
        printf("Incorrect input");
        free(numbers);
        free(comparators);
        return 1;
    }
    if(operator < 0 || operator > 3){
        printf("Incorrect input data");
        free(numbers);
        free(comparators);
        return 2;
    }

    sort_int(numbers, size, *(comparators+operator));
    for(int i = 0; i < size; i++){
        printf("%d ",*(numbers+i));
    }

    free(comparators);
    free(numbers);
    return 0;
}