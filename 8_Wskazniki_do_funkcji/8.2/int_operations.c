#include "int_operations.h"

int calculate(int num1, int num2, int(*function)(int, int)){
    return (*function)(num1,num2);
}
int add_int(int num1, int num2){
    return num1+num2;
}

int sub_int(int num1, int num2){
    return num1-num2;
}

int mul_int(int num1, int num2){
    return num1*num2;
}

int div_int(int num1, int num2){
    if(num2 == 0) return 0;
    return num1/num2;
}

int (*get_function(enum operations_t operation))(int, int){
    int (*funcs[4])(int, int);
    *funcs = add_int;
    *(funcs+1) = sub_int;
    *(funcs+2) = mul_int;
    *(funcs+3) = div_int;

    int (*function_poitner)(int, int);
    
    switch (operation)
    {
    case op_add:
        function_poitner = *funcs;
        break;
    case op_sub:
        function_poitner = *(funcs+1);
        break;
    case op_div:
        function_poitner = *(funcs+3);
        break;
    case op_mul:
        function_poitner = *(funcs+2);
        break;    
    default:
        function_poitner = NULL;
    }
    return function_poitner;
}