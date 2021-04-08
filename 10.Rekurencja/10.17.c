#include <stdio.h>

long power_rec(int a, int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    else return a*power_rec(a,n-1);
}

int special_sum(int num, int exponent){
    if(num == 0) return 0;
    else return ((num % 10) * power_rec(3,exponent)) + special_sum(num/10,exponent+1);
}

int is_divisible_by_7(int number){
    if(((number>0) ? number : -number) < 10){
        if (number % 10 == 7 || number % 10 == -7 || number % 10 == 0) return 1;
        else return 0;
    }
    else return (is_divisible_by_7(special_sum(number,0)));
}

int main(){

    printf("Liczbe do sprawdzenia prosze: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(is_divisible_by_7(num)){
        printf("YES");
    } else {
        printf("NO");
    }


    return 0;
}