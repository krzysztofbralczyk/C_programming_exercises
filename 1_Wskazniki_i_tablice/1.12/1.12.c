#include <stdio.h>
#include "vector_utils.h"
// #include "vector_utils.c"


int main(){

    printf("Your array please: ");
    float numbers[100] = {0};
    int vector_length = read_vector_float(numbers,100,-1);
    if(vector_length == 0){
        printf("Not enough data available");
        return 3;
    } else if(vector_length == -2){
        printf("Incorrect input");
        return 1;
    }
    while(getchar() != '\n');

    int histogram[11] = {0};
    
    int create_hist_result = create_histogram(numbers,vector_length,histogram,11);
    if(create_hist_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(histogram,11);

    return 0;
}


