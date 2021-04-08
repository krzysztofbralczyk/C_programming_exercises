#include <stdio.h>

int main(){

    char* string = "Ala Ma Kota a kot Ma AlE";
    for(int i = 0; *(string+i) != '\0'; i++){
        putchar(*(string+i));
    }

    return 0;
}