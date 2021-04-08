#include <stdio.h>

unsigned long factorial_rec(int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    else return n*factorial_rec(n-1);
}

int main(){

    printf("Liczbe z zakresu 1-20 prosze: ");
    int number;
    if(!scanf("%d",&number)){
        printf("Incorrect input");
        return 1;
    }
    if(number > 20 || number < 0){
        printf("Incorrect input data");
        return 2;
    }
    
    printf("%lu",factorial_rec(number));
    return 0;
}

// W programie nie wolno używać zmiennych globalnych.
// W programie nie wolno używać słowa kluczowego static.
// W programie nie wolno używać pętli.