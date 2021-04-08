#include <stdio.h>
#include "vector_utils.h"
// #include "vector_utils.c"


int main(){

    printf("Your array please: ");
    int numbers[150];
    int vector_length = read_vector(numbers,150,0);
    if(vector_length == 0){
        printf("Not enough data available");
        return 3;
    } else if(vector_length == -2){
        printf("Incorrect input");
        return 1;
    }
    while(getchar() != '\n');

    printf("How many positions do your want to shift: ");
    int shift_times;
    if(!scanf("%d",&shift_times)){
        printf("Incorrect input");
        return 1;
    }

    printf("Which direction do you want to rotate array? (1-right, 2-left) : ");
    int rotate_direction;
    if(!scanf("%d",&rotate_direction)){
        printf("Incorrect input");
        return 1;
    }

    int shift_result = shift(numbers,vector_length,shift_times,rotate_direction);
    if(shift_result == 1){
        printf("Incorrect input data");
        return 2;
    }

    display_vector(numbers,vector_length);








    return 0;
}


