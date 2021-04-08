#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int horner(const char binary[]){
    int sum = 0;
    for(int i = 0; binary[i] != '\0'; i++){
        if(binary[i] != '0' && binary[i] != '1') return -1;
        sum *= 2;
        sum += binary[i] - '0';
    }
    return sum;
}


int main(){

    printf("Liczbe dwojkowa prosze:  ");
    char A[17] = {'\0'};
    scanf("%16[^\n]",A);
    int horner_result = horner(A);
    if(horner_result == -1){
        printf("Incorrect input");
        return 1;
    }
    printf("%d",horner_result);
    // printf("%d",horner("11100111"));
    return 0;
}
