#include <stdio.h>

unsigned long long decimal_to_octal(unsigned int number){
    if (number == 0) return 0;
    else return 10 * decimal_to_octal(number/8) + number%8;
}

int main(){

    printf("Liczbe do konwersji prosze: ");
    unsigned int num;
    if(!scanf("%ud",&num)){
        printf("Incorrect input");
        return 1;
    }

    printf("%llu",decimal_to_octal(num)); 
    return 0;
}