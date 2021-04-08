#include <stdio.h>

long int fibonacci(int n){
    if(n < 0) return -1;
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){

printf("Liczbe prosze: ");
    int n;
    if(!scanf("%d",&n)){
        printf("Incorrect input");
        return 1;
    }


    long int fibo_result = fibonacci(n);
    if(fibo_result == -1){
        printf("Incorrect input data");
        return 2;
    }

    printf("%ld",fibo_result);
    return 0;
}