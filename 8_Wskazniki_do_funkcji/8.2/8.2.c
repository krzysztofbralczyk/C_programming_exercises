#include <stdio.h>
#include "int_operations.h"
// #include "int_operations.c"
int main(){
    int num1, num2;
    printf("Enter numbers: ");
    if(scanf("%d %d",&num1, &num2) != 2){
        printf("Incorrect input");
        return 1;
    }
    int operation;
    printf("Choose operation(0 - 3): ");
    if(!scanf("%d",&operation)){
        printf("Incorrect input");
        return 1;
    }
    if(operation < 0 || operation > 3){
        printf("Incorrect input data");
        return 2;
    }

    printf("%d",calculate(num1,num2,get_function(operation)));
    return 0;
}

