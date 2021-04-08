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
    if(num2 == 0) return 666;
    return num1/num2;
}