


#include <stdio.h>
#include "bit_set.h"

int main(){
    union bit_set *ptest, test;
    ptest = &test;
    printf("Podaj liczbe calkowita: ");
    if(!scanf("%u",&(ptest->number))){
        printf("Incorrect input");
        return 1;
    }
    int sum = 0;
    for(int i = 0; i < 4; i++){
        sum += (*(ptest->c+i)).bit1;
        sum += (*(ptest->c+i)).bit2;
        sum += (*(ptest->c+i)).bit3;
        sum += (*(ptest->c+i)).bit4;
        sum += (*(ptest->c+i)).bit5;
        sum += (*(ptest->c+i)).bit6;
        sum += (*(ptest->c+i)).bit7;
        sum += (*(ptest->c+i)).bit8;
    }
    if(sum % 2 == 0){
        printf("YES");
    } else printf("NO");

    return 0;
}