#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int stats(int *sum, float *avg, int num,...){
    if(sum == NULL || avg == NULL || num <= 0) return 1;
    *sum = 0;
    va_list args;
    va_start(args, num);

    for(int i = 0; i < num; i++){
        *sum += va_arg(args,int);
    }
    *avg = (float)*sum / num;
    va_end(args);
    return 0;
}
int main(){
    printf("Enter number of elements: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }
    if(num < 1 || num > 3){
        printf("Incorrect input data");
        return 2;
    }
    int nums[3];
    printf("Enter numbers: ");
    for(int i = 0; i < num; i++){
        if(!scanf("%d",nums+i)){
            printf("Incorrect input");
            return 1;
        }
    }
    int sum = 0;
    float avg;
    if(num == 1) stats(&sum,&avg,num,nums[0]);
    if(num == 2) stats(&sum,&avg,num,nums[0],nums[1]);
    if(num == 3) stats(&sum,&avg,num,nums[0],nums[1], nums[2]);
    printf("%d %f",sum, avg);
    return 0;
}