#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int get_sequence_length(const char tab[], int id){
    int counter = 0;
    static int i = 0;
    if(!id) i = 0;
    for(; tab[i] != '\0'; i++){
        while(tab[i] == '1'){ 
            i++;
            counter++;
        }
        if(counter != 0) return counter;
    }
    return -1;
}

int count_sequences(const char tab[]){
    int counter = 0;
    for(int i = 0; tab[i] != '\0'; i++){
        if(tab[i] < '0' || tab[i] > '9') return -1;
        if(tab[i] == '1'){
            counter++;
            while(tab[i] == '1') i++;
        }
    }
    return counter;
}


int main(){
    printf("Liczbe prosze: ");
    char A[201] = {'\0'};
    scanf("%200[^\n]",A);

    int count_result = count_sequences(A);

    if(count_result == -1){
        printf("Incorrect input");
        return 1;
    }
    printf("%d",count_result);
    printf("\n");

    int a = get_sequence_length(A,1);
    while(a != -1){
        printf("%d",a);
        a = get_sequence_length(A,1);
        printf("\n");
    }


    return 0;
}
