#include <stdio.h>

int digits_in_number(unsigned long long number, unsigned int digit){
    if (number == 0){
        if (digit == 0)return 1;
        else return 0;
    }
    if (number/10 == 0) return (number%10 == digit);
    else return digits_in_number(number/10,digit) + (number%10 == digit);
}

int main(){

    printf("Liczbe w ktorej bede szukac prosze: ");
    unsigned long long int num;
    if(!scanf("%llu",&num)){
        printf("Incorrect input");
        return 1;
    }

    printf("Cyfre ktora bede szukac prosze: ");
    unsigned int digit;
    if(!scanf("%ud",&digit)){
        printf("Incorrect input");
        return 1;
    }

    if(digit > 9){
        printf("Incorrect input data");
        return 2;
    }

    printf("%d",digits_in_number(num,digit));

    return 0;
}