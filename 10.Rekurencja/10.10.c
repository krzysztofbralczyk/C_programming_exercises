#include <stdio.h>

int sum_of_digits(long long number){
    if(number / 10 == 0) return ((number>0)?number:-number) % 10;
    else return ((number>0)?number:-number) % 10 + sum_of_digits(number/10);
} 

int main(){
    printf("N prosze: ");
    long long int x;
    if(!scanf("%lld",&x)){
        printf("Incorrect input");
        return 1;
    }

    printf("%d",sum_of_digits(x));
    return 0;
} 