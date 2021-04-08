#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[]){
    int i = 0;
    while(tab[i] != '\0') i++;
    return i;
}

int find_any(const char tab[], const char tab2[]){
    int i = 0;
    while(tab[i] != '\0'){
        int j = 0;
        while(tab2[j] != '\0'){
            if(tab[i] == tab2[j]) return i;
            j++;
        }
        i++;
    }
    return -1;
}

int rfind_any(const char tab[], const char tab2[]){
    int i = my_strlen(tab)-1;
    while(i >= 0){
        int j = 0;
        while(tab2[j] != '\0'){
            if(tab[i] == tab2[j]) return i;
            j++;
        }
        i--;
    }
    return -1;
}

int main(){

    printf("Ciag znakow prosze:  ");
    char A[1001] = {0};        //tablica
    scanf("%1000[^\n]",A);     //input
    while(getchar()!='\n');    //czysc bufor

    printf("Drugi ciag znakow prosze:  ");
    char B[1001] = {0};
    scanf("%1000[^\n]",B);
    while(getchar()!='\n');

    printf("%d\n%d",find_any(A,B),rfind_any(A,B));
    return 0;
}


