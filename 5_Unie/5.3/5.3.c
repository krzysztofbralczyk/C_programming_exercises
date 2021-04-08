


#include <stdio.h>
#include "bit_set.h"

int main(){
    union bit_set *ptest, test;
    ptest = &test;
    int number;
    printf("Podaj liczbe calkowita: ");
    if(!scanf("%d",&(number))){
        printf("Incorrect input");
        return 1;
    }
    ptest->number = (char) number;
    printf("%d %d %d %d %d %d %d %d",ptest->c.bit8, ptest->c.bit7, ptest->c.bit6, ptest->c.bit5, ptest->c.bit4, ptest->c.bit3, ptest->c.bit2, ptest->c.bit1);

    return 0;
}