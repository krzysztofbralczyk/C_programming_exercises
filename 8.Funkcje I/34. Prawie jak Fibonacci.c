#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int fibonacci(unsigned int a, unsigned int b, unsigned int expected){
    int fiboCounter = 1;
    while(a + b <= expected){
        if(a + b == expected) return fiboCounter;

        b = a + b;
        a = b - a;
        fiboCounter++;
    }
    return -1;
}

int main(){
    //input start
    printf("Zachecam do podania liczby: ");
    int n;
    if(!scanf("%d",&n)){
        printf("Incorrect input");
        return 1;
    }

    if(n>20000 || n < 1){
        printf("Incorrect input data");
        return 2;
    }
    //input end
    

    int fib_max = 0, found[2] = {0};
    // printf("%d\n",fibonacci(1,1,n));
    for(int a = 1; a < n; a++){
        for(int b = a; b < n; b++){
            int temp = fibonacci(a,b,n);
            if(temp != -1 && temp > fib_max){
                fib_max = temp;
                found[0] = a;
                found[1] = b;
            } 
        }
    }
    printf("%d %d",found[0],found[1]);

    return 0;
}
