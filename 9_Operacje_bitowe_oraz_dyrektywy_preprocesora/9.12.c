#include <stdio.h>
#include "functions.h"


int main(){

    printf("Enter data type: ");
    int data_type;

    if(!scanf("%d",&data_type)){
        printf("Incorrect input");
        return 1;
    }

    if(data_type != 0 && data_type != 1){
        printf("Incorrect input data");
        return 2;
    }

    printf("Enter numbers: ");
    

    if(data_type == 0){
        int num1, num2;
        if(scanf("%d %d",&num1, &num2) != 2){
            printf("Incorrect input");
            return 1;
        }
        printf("%d\n%d\n%d\n%d",SQR(num1),SQR(num2),MAX(num1,num2),MIN(num1,num2));
    } else {
        float num1, num2;
        if(scanf("%f %f",&num1, &num2) != 2){
            printf("Incorrect input");
            return 1;
        }
        printf("%f\n%f\n%f\n%f",SQR(num1),SQR(num2),MAX(num1,num2),MIN(num1,num2));
    }

    return 0;
}