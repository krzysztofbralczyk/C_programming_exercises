// Jak z wyświetlonych bajtów 68 67 66 65 powstaje wartość 1094861636?
//  68 * 256^0 + 67 * 256^1 + 66 * 256^2 + 65 * 256^3 , 256 jest podstawa bo bajt = 8 bitów = 1111 1111 = 256 liczb w systemie dzisiętnym, od 0 do 255

// Jak nazywa się kolejność 68 67 66 65 i 65 66 67 68?
// Od najstarszego bitu i od najmłodszego bitu


#include <stdio.h>
#include "byte_set.h"

int main(){
    union byte_set *ptest, test;
    ptest = &test;
    printf("Podaj liczbe calkowita: ");
    if(!scanf("%d",&(ptest->number))){
        printf("Incorrect input");
        return 1;
    }
    printf("%d %d %d %d",(unsigned char)*(ptest->c+0),(unsigned char)*(ptest->c+1),(unsigned char)*(ptest->c+2),(unsigned char)*(ptest->c+3));

    return 0;
}