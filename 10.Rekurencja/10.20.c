#include <stdio.h>

unsigned long long octal_to_decimal(unsigned long long num){
    if (num == 0) return 0;
    else return octal_to_decimal(num/10) * 8 + num%10;
}

int is_octal(unsigned long long num){
    if( num == 0 ) return 1;
    else{
        if( num % 10 > 7) return 0;
        else return is_octal(num/10);
    }
}

int main(){

    printf("Liczbe do konwersji prosze: ");
    unsigned long long int num;
    if(!scanf("%llu",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(!is_octal(num)){
        printf("Incorrect input data");
        return 2;
    }

    printf("%llu",octal_to_decimal(num));

    return 0;
}
