#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "functions.h"



int main(){
    printf("Enter data type: ");
    int data_type;
    if(!scanf("%d",&data_type)){
        printf("Incorrect input");
        return 1;
    }
    if(data_type < 0 || data_type > 2){
        printf("Incorrect input data");
        return 2;
    }
    int counter_1 = 0, counter_0 = 0;
    if(data_type == 0){
        unsigned int number;
        printf("Enter integer: ");
        if(!scanf("%u",&number)){
            printf("Incorrect input");
            return 1;
        }
        COUNT_BITS(number, &counter_1, &counter_0);
        printf("%d\n%d\n",counter_1,counter_0);
        DISPLAY_BITS(number);
        printf("\n");
        REVERSE_BITS(&number);
        DISPLAY_BITS(number);
    }
    else if(data_type == 1){
        unsigned short int number;
        printf("Enter integer: ");
        if(!scanf("%hu",&number)){
            printf("Incorrect input");
            return 1;
        }
        COUNT_BITS(number, &counter_1, &counter_0);
        printf("%d\n%d\n",counter_1,counter_0);
        DISPLAY_BITS(number);
        printf("\n");
        REVERSE_BITS(&number);
        DISPLAY_BITS(number);
    }
    else {
        unsigned long long int number;
        printf("Enter integer: ");
        if(!scanf("%llu",&number)){
            printf("Incorrect input");
            return 1;
        }
        COUNT_BITS(number, &counter_1, &counter_0);
        printf("%d\n%d\n",counter_1,counter_0);
        DISPLAY_BITS(number);
        printf("\n");
        REVERSE_BITS(&number);
        DISPLAY_BITS(number);
    }
    
  
    return 0;
}