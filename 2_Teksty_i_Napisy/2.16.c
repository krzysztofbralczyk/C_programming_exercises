#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int validate_expression(const char* expr);
int calculate(const char* expr, float* result);
void execute_operation(float num1, int num2, char operation, float* result);

int main() {
    printf("Podaj liczbe: ");
    char expression[201];
    scanf("%200[^\n]", expression);

    if (validate_expression(expression) != 1) {
        printf("Incorrect input");
        return 1;
    }

    float result;

    int correct = calculate(expression, &result);

    if (!correct) {
        printf("Incorrect input");
        return 1;
    }
    printf("%.2f", result);
    return 0;
}
int calculation(char operator, int current_number, char* digits, const char* expr, float* result) {
    if (operator == '\0') return 1;
    else {
        current_number += (strspn(expr + current_number, digits) + 1);
        int number2 = atoi(expr + current_number);
        execute_operation(*result, number2, operator, result);
        operator = *(expr + current_number + strspn(expr + current_number, digits));
        if (operator == '/' && *(expr + current_number + strspn(expr + current_number, digits) + 1) == '0') return 0;
        return calculation(operator,current_number, digits, expr, result);
    }
    return 1;
}

int calculate(const char* expr, float* result) {
    if (result == NULL) return 0;
    if (validate_expression(expr) != 1) return 0;

    char* digits = "0123456789";

    int current_number = 0;
    char operator = *(expr + strspn(expr, digits));
    if (*(expr + strspn(expr, digits) + 1) == '0') return 0;
    *result = atoi(expr);
    int return_value = calculation(operator,current_number, digits, expr, result);
    return return_value;
}

int validate(char* pch1, char* pch2, char* operators) {
    if (pch1 == NULL || pch2 == NULL) return 1;
    if (pch1 + 1 == pch2) return 0;
    else {
        pch1 = pch2;
        pch2 = strpbrk(pch1 + 1, operators);
        return validate(pch1, pch2, operators);
    }
    return 1;
}
int only_nums_and_ops(const char* expr) {
    if (*expr == '\0') return 1;
    if (!isdigit(*(expr)) && *(expr) != '/' && *(expr) != '*' && *(expr) != '+' && *(expr) != '-') return 0;
    else return only_nums_and_ops(expr + 1);
}
int validate_expression(const char* expr) {
    if (expr == NULL) return -1;
    if (!isdigit(*expr)) return 0;
    if (!isdigit(*(expr + strlen(expr) - 1))) return 0;
    if (!only_nums_and_ops(expr)) return 0;

    char* operators = "/+-*";
    char* pch1 = strpbrk(expr, operators);
    if (pch1 == NULL) return 1;
    char* pch2 = NULL;
    if (pch1 != NULL) pch2 = strpbrk(pch1 + 1, operators);
    if (pch2 == NULL) return 1;
    int return_value = validate(pch1, pch2, operators);
    return return_value;
}

void execute_operation(float num1, int num2, char operation, float* result) {
    if (operation == '+') {
        *result = num1 + (float)num2;
    }
    if (operation == '-') {
        *result = num1 - (float)num2;
    }
    if (operation == '*') {
        *result = num1 * (float)num2;
    }
    if (operation == '/') {
        *result = num1 / (float)num2;
    }
}