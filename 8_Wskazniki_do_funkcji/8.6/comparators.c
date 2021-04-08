#include "comparators.h"

int comp_int(int num1, int num2){
    if(num1 > num2) return 1;
    else if(num2 > num1) return -1;
    else return 0;
}
int comp_int_abs(int num1, int num2){
    if(abs(num1) > abs(num2)) return 1;
    else if (abs(num2) > abs(num1)) return -1;
    else return 0;
}
int comp_int_length(int num1, int num2){
    int num1_length = 0, num2_length = 0;
    while(num1 != 0){
        num1 /= 10;
        num1_length++;
    }

    while(num2 != 0){
        num2 /= 10;
        num2_length++;
    }

    if(num1_length > num2_length) return 1;
    else if (num2_length > num1_length) return -1;
    else return 0;
}
int comp_int_digits_sum(int num1, int num2){
   int num1_sum = 0, num2_sum = 0;
    while(num1 != 0){
        num1_sum += abs(num1%10);
        num1 /= 10;
    }

    while(num2 != 0){
        num2_sum += abs(num2%10);
        num2 /= 10;
    } 

    if(num1_sum > num2_sum) return 1;
    else if (num2_sum > num1_sum) return -1;
    else return 0;
}
int sort_int(int* table, int size, int(*comparator)(int,int)){
    if(table == NULL || size <= 0 || comparator == NULL) return 1;
    
    int sorted = 0;
    while(!sorted){
        sorted = 1;
        for(int i = 1; i < size; i++){
            if(comparator(*(table+i-1),*(table+i)) > 0){
                sorted = 0;
                int temp = *(table+i);
                *(table+i) = *(table+i-1);
                *(table+i-1) = temp;
            }
        }
    }
    return 0;
}