#ifndef INT_OPERATIONS_H
#define INT_OPERATIONS_H
#include <stdio.h>
enum operations_t {op_add, op_sub, op_div, op_mul};
int calculate(int num1, int num2, int(*function)(int, int));
int add_int(int num1, int num2);
int sub_int(int num1, int num2);
int mul_int(int num1, int num2);
int div_int(int num1, int num2);
int (*get_function(enum operations_t operation))(int, int);
#endif