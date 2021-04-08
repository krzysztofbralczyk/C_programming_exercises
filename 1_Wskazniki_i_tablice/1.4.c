#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int random_number[20];
    int *totally_useless_pointer = random_number;

    for(int i = 0; i < 20; i++){
        *(totally_useless_pointer+i) = rand();
    }

    for(int i = 0; i < 20; i++){
        printf("%d ",*(totally_useless_pointer+i));
    }
    printf("\n");

    for(int i = 0; i < 20; i+=2){
        printf("%d ",*(totally_useless_pointer+i));
    }
    return 0;
}