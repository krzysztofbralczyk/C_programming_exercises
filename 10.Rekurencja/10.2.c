#include <stdio.h>

long power_rec(int a, int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    else return a*power_rec(a,n-1);
}

int main(){

    printf("Podstawe prosze: ");
    int base;
    if(!scanf("%d",&base)){
        printf("Incorrect input");
        return 1;
    }

    printf("Wykladnik prosze: ");
    int exponent;
    if(!scanf("%d",&exponent)){
        printf("Incorrect input");
        return 1;
    }
    if(exponent < 0){
        printf("Incorrect input data");
        return 2;
    }
    
    printf("%ld",power_rec(base,exponent));
    return 0;
}