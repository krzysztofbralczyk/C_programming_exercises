#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int add_comas(long long a, char output[], int size){
    if(size <= 1) return 1;

    if(a == 0){
        output[0] = '0';
        return 0;
    }

    int negative = 0;
    if(a < 0){
        negative = 1;
        a = -a;
    }

    int triplets_counter = 0;
    int output_idx = 0;
    while(a != 0){
        if(output_idx > size-2) return 1;   //-1 na terminator -1 bo porownuje index nie rozmiar
        output[output_idx] = (a % 10) + '0';
        output_idx++;
        triplets_counter++;
        a /= 10;
        if(a == 0) break;
        if(triplets_counter == 3 /*&& a != 0*/){
            triplets_counter = 0;
            if(output_idx > size-2) return 1;
            output[output_idx] = ',';
            output_idx++;
        }
    }
    if(negative){
        if(output_idx > size-2) return 1;
        output[output_idx] = '-';
        output_idx++;
    }

    for(int i = 0; i < output_idx/2; i++){
        int temp = output[i];
        output[i] = output[output_idx-1-i];
        output[output_idx-1-i] = temp;
    }

    output[output_idx] = '\0';
    return 0;
}




int main(){
    long long int number;
    printf("liczbe prosze: ");
    if(!scanf("%lld",&number)){
        printf("Incorrect input");
        return 1;
    }
    char A[30] = {'\0'};
    int add_comas_check = add_comas(number,A,30);
    if(add_comas_check == -1){
        printf("Incorrect input");
        return -1;
    }

    for(int i = 0; A[i] != '\0'; i++){
        printf("%c",A[i]);
    }

    return 0;
}
