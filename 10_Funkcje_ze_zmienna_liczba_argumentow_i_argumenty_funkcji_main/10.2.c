#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
int concatenate(char* , int, int, ...);

int main(){
    char* test = (char*)malloc(6039); //WHAT DOES DANTE WANT!
    if(test == NULL){printf("Failed to allocate memory"); return 8;}
    free(test);

    printf("Podaj liczbe tekstow do wprowadzenia: ");
    int amount;
    if(!scanf("%d",&amount)){
        printf("Incorrect input");
        return 1;
    }

    if(amount < 2 || amount > 4){
        printf("Incorrect input data");
        return 2;
    }

    char** texts = (char**)malloc(amount*sizeof(char*));
    if(texts == NULL){printf("Failed to allocate memory"); return 8;}
    for(int i = 0; i < amount; i++){
        *(texts+i) = (char*)malloc(1001*sizeof(char));
        if(*(texts+i) == NULL) {
            for(int j = 0; j<i; j++) {free(*(texts+j));}
            free(texts);
            printf("Failed to allocate memory");
            return 8;
        }
    }

    char* result = (char*)malloc( 4004 * sizeof(char) );
    if(result == NULL){
        for(int i = 0; i < amount; i++) free(*(texts+i));
        free(texts);
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Podaj teksty: ");
    while(getchar()!= '\n');
    for(int i = 0; i < amount; i++){
        scanf("%1000[^\n]",*(texts+i));
        while(getchar()!='\n');
    }
    int concat_returned;
    if(amount == 2){
        concat_returned = concatenate(result,4004, amount,*(texts+0), *(texts+1));
    }
    else if(amount == 3){
        concat_returned = concatenate(result,4004, amount, *(texts+0), *(texts+1), *(texts+2));
    }
    else if(amount == 4){
        concat_returned = concatenate(result,4004, amount, *(texts+0), *(texts+1), *(texts+2), *(texts+3));
    }
    else{printf("Just how?!");}
    if(concat_returned == 2){
        free(texts);
        printf("Failed to allocate memory");
        return 8;
        }
    printf("%s",result);
    for(int i = 0; i < amount; i++){free(*(texts+i));}
    free(texts);
    free(result);
    return 0;
}

int concatenate(char* bufor , int bufor_size, int N, ...){
    if(N < 2 || bufor == NULL || bufor_size < 1 ) return 1;

    va_list args;
    va_start(args,N);
    for(int i = 0; i < bufor_size; i++) *(bufor + i) = '\0';

    for(int i = 0; i < N; i++){
        char* temp = va_arg(args, char*);
        if(strlen(temp) + strlen(bufor) + 2 > (unsigned)bufor_size) {va_end(args); return 2;}
        if(i!=0)strcat(bufor," ");
        strcat(bufor,temp);
    }


    va_end(args);
    return 0;
}