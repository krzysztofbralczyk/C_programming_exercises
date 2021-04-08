// Jaki typ będzie reprezentowało słowo?
// short int


// Czym jest słowo?
// Szukałem, pytałem, nie wiem


#include <stdio.h>
#include "word_set.h"

int main(){
    union word_set *ptest, test;
    ptest = &test;
    printf("Podaj liczbe calkowita: ");
    if(!scanf("%d",&(ptest->number))){
        printf("Incorrect input");
        return 1;
    }
    printf("%d %d",(unsigned short)*(ptest->c+0),(unsigned short)*(ptest->c+1));

    return 0;
}