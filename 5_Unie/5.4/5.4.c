


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

    printf("%u\n",ptest->number);
    printf("%d %d\n",(unsigned short)*(ptest->c1+0),(unsigned short)*(ptest->c1+1));
    printf("%d %d %d %d\n",(unsigned char)*(ptest->c2+0),(unsigned char)*(ptest->c2+1),(unsigned char)*(ptest->c2+2),(unsigned char)*(ptest->c2+3));
    printf("%d%d%d%d%d%d%d%d ",(*(ptest->c+0)).bit8, (*(ptest->c+0)).bit7, (*(ptest->c+0)).bit6, (*(ptest->c+0)).bit5, (*(ptest->c+0)).bit4, (*(ptest->c+0)).bit3, (*(ptest->c+0)).bit2, (*(ptest->c+0)).bit1) ;
    printf("%d%d%d%d%d%d%d%d ",(*(ptest->c+1)).bit8, (*(ptest->c+1)).bit7, (*(ptest->c+1)).bit6, (*(ptest->c+1)).bit5, (*(ptest->c+1)).bit4, (*(ptest->c+1)).bit3, (*(ptest->c+1)).bit2, (*(ptest->c+1)).bit1) ;
    printf("%d%d%d%d%d%d%d%d ",(*(ptest->c+2)).bit8, (*(ptest->c+2)).bit7, (*(ptest->c+2)).bit6, (*(ptest->c+2)).bit5, (*(ptest->c+2)).bit4, (*(ptest->c+2)).bit3, (*(ptest->c+2)).bit2, (*(ptest->c+2)).bit1) ;
    printf("%d%d%d%d%d%d%d%d",(*(ptest->c+3)).bit8, (*(ptest->c+3)).bit7, (*(ptest->c+3)).bit6, (*(ptest->c+3)).bit5, (*(ptest->c+3)).bit4, (*(ptest->c+3)).bit3, (*(ptest->c+3)).bit2, (*(ptest->c+3)).bit1) ;

    return 0;
}