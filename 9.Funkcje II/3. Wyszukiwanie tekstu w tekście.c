#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[]){
    int i = 0;
    while(tab[i] != '\0') i++;
    return i;
}

int find_string(const char tab[], const char tab2[]){
    int i = 0;
    int idx_of_first_letter;
    while(tab[i] != '\0'){
        idx_of_first_letter = i;
        int j = 0;
        while(tab[i] == tab2[j]){
            i++;
            j++;
            if(tab2[j] == '\0') return idx_of_first_letter;
        }
        i++;
    }
    return -1;
}
int rfind_string(const char tab[], const char tab2[]){
    int i = my_strlen(tab)-1;
    while(i >= 0){
        int j = my_strlen(tab2)-1;
        if(j<0) return -1;   // dla Clanga
        while(tab[i] == tab2[j]){
            i--;
            j--;
            if(j<0) return i+1;
            if(i<0) return -1; //dla Clanga
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

    printf("%d\n%d",find_string(A,B),rfind_string(A,B));
    return 0;
}


