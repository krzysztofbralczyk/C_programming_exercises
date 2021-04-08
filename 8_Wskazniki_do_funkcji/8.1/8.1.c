#include <stdio.h>
#include "int_operations.h"
// #include "int_operations.c"

int main(){

    int (*functions[4])(int,int);
    *functions = add_int;
    *(functions+1) = sub_int;
    *(functions+2) = mul_int;
    *(functions+3) = div_int;
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

    int (*function_poitner)(int, int);
    switch (operation)
    {
    case 0:
        function_poitner = *functions;
        break;
    case 1:
        function_poitner = *(functions+1);
        break;
    case 2:
        function_poitner = *(functions+3);
        break;
    case 3:
        function_poitner = *(functions+2);
        break;    
    default:
        break;
    }
    int calculate_returned = calculate(num1, num2, function_poitner);
    printf("%d", calculate_returned);
    return 0;
}