#include <stdio.h>

int num_length(unsigned long a){
    if(a == 0) return 0;
    else return num_length(a/10) + 1;
}

long power_rec(int a, int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    else return a*power_rec(a,n-1);
}

unsigned long reverse_number(unsigned long a){
    if(a == 0) return 0;
    else return reverse_number(a/10) + (a%10) * power_rec(10,num_length(a)-1);
}

int main(){

    printf("num1 prosze: ");
    unsigned long int num1;
    if(!scanf("%lu",&num1)){
        printf("Incorrect input");
        return 1;
    }

    printf("num2 prosze: ");
    unsigned long int num2;
    if(!scanf("%lu",&num2)){
        printf("Incorrect input");
        return 1;
    }

    printf("%lu",reverse_number(reverse_number(num1) + reverse_number(num2)));


    return 0;
}