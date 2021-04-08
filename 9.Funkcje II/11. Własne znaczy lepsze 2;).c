#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int my_strcmp(const char tab[], const char tab2[]){
    int i = 0;
    for(; tab[i] != '\0' && tab2[i] != '\0';i++){
        if(tab[i] != tab2[i]){
            if(tab[i] > tab2[i]) return 1;
            else return -1;
        }
    }

    if(tab[i] == tab2[i]) return 0;
    if(tab[i] < tab2[i]) return -1;
    if(tab[i] > tab2[i]) return 1;
    return 1000; //dla Dante
}
int my_strncmp(const char tab[], const char tab2[], unsigned int n){
    int i = 0;
    for(; i < (int)n && tab[i] != '\0' && tab2[i] != '\0'; i++){
        if(tab[i] != tab2[i]){
            if(tab[i] > tab2[i]) return 1;
            else return -1;
        }
    }
    if(i == (int)n) return 0;
    if(tab[i] == tab2[i]) return 0;
    if(tab[i] < tab2[i]) return -1;
    if(tab[i] > tab2[i]) return 1;
    return 1000; //dla Dante
}

int main(){

printf("Ciag znakow prosze:  ");
char A[101] = { 0 };
scanf("%100[^\n]", A);
while (getchar() != '\n');

printf("Ciag znakow prosze:  ");
char B[101] = { 0 };
scanf("%100[^\n]", B);
while (getchar() != '\n');

printf("Liczbe znakow do porownania prosze:  ");
int n_to_compare;
if(!scanf("%d",&n_to_compare)){
    printf("Incorrect input");
    return 1;
}
if(n_to_compare <= 0){
    printf("Incorrect input");
    return 1;
}

printf("strcmp %d\n",my_strcmp(A,B));
printf("strncmp %d",my_strncmp(A,B,n_to_compare));


return 0;
}
