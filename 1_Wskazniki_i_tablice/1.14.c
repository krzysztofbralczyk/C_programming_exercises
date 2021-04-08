#include <stdio.h>
int add(const int *first, const int *second, int* result);
int subtract(const int *first, const int *second, int* result);
int multiply(const int *first, const int *second, int* result);
int divide(const int *first, const int *second, float* result);

int main(){
    int num1,num2,operation_returned,int_result,dividing = 0;
    char operation;
    float float_result;
    printf("Podaj dzialanie: ");
    if(scanf("%d%c%d",&num1,&operation,&num2) != 3){
        printf("Incorrect input");
        return 1;
    }
    
    switch(operation){
        case '+':
            operation_returned = add(&num1,&num2,&int_result);
            break;
        case '-':
            operation_returned = subtract(&num1,&num2,&int_result);
            break;
        case '*':
            operation_returned = multiply(&num1,&num2,&int_result);
            break;
        case '/':
            if(num2 == 0){
                printf("Operation not permitted");
                return 4;
            }
            operation_returned = divide(&num1,&num2,&float_result);
            dividing = 1;
            break;
        default:
            printf("Incorrect input");
            return 1;
    }

    if(operation_returned == 1){
        printf("Incorrect input");
        return 1;
    }
    if(dividing) printf("%lf",float_result);
    else printf("%d",int_result);

    return 0;
}

int add(const int *first, const int *second, int* result){
    if(first == NULL || second == NULL || result == NULL) return 1;
    *result = *second + *first;
    return 0;
}
int subtract(const int *first, const int *second, int* result){
    if(first == NULL || second == NULL || result == NULL) return 1;
    *result = *first - *second;
    return 0;
}
int multiply(const int *first, const int *second, int* result){
    if(first == NULL || second == NULL || result == NULL) return 1;
    *result = *second * *first;
    return 0;
}
int divide(const int *first, const int *second, float* result){
    if(first == NULL || second == NULL || *second == 0 || result == NULL) return 1;
    *result = (float)*first / *second;
    return 0;
}