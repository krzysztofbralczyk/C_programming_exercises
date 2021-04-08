#include <stdio.h>

int sum_of_digits(long long number){
    if(number / 10 == 0) return ((number>0)?number:-number) % 10;
    else return ((number>0)?number:-number) % 10 + sum_of_digits(number/10);
}

int is_divisible_by_3(int number){
    if(((number>0) ? number : -number) < 10){
        if (number % 10 == 3 || number % 10 == 6 || number % 10 == 9 || number % 10 == -3 || number % 10 == -6 || number % 10 == -9 || number % 10 == 0) return 1;
        else return 0;
    }
    else return (is_divisible_by_3(sum_of_digits(number)));
}

int main(){

    printf("Liczbe do sprawdzenia prosze: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(is_divisible_by_3(num)){
        printf("YES");
    } else {
        printf("NO");
    }
 
    return 0;
}