#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    double random_number[20];
    double *totally_useless_pointer = random_number;

    for(int i = 0; i < 20; i++){
        *(totally_useless_pointer+i) = rand()%100/0.21345;
    }

    for(int i = 0; i < 20; i++){
        printf("%lf ",*(totally_useless_pointer+i));
    }
    printf("\n");

    for(int i = 0; i < 20; i+=2){
        printf("%lf ",*(totally_useless_pointer+i));
    }
    return 0;
}