#include <stdio.h>

unsigned long sum_rec(int n){
    if(n <= 0) return 0;
    if(n == 1) return 1;
    else return n+sum_rec(n-1);
}

int main(){

printf("Liczbe prosze: ");

    int n;
    if(!scanf("%d",&n)){
        printf("Incorrect input");
        return 1;
    }


    unsigned long int sum = sum_rec(n);
    if(sum == 0){
        printf("Incorrect input data");
        return 2;
    }

    printf("%lu",sum);
    return 0;
}