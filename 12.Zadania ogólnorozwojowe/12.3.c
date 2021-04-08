#include <stdio.h>

int count_digits(double num){
    int counter = 0;
    while(num >= 1){
        counter++;
        num = num/10;
    }
    return counter;
}

int take_digit(double num, int position_from_right){
    for(int i = 0; i < position_from_right; i++) num /= 10;
    int result = (int)num%10;
    return result;
}

int main(){

    double num1,num2;

    printf("num1 please ");
    scanf("%lf",&num1);
    printf("num2 please ");
    scanf("%lf",&num2);
    
    int product_dig_count = count_digits(num1*num2);
    printf("%*.0lf\n",product_dig_count,num1);
    printf("%*.0lf\n",product_dig_count,num2);
    for(int i = 0; i < product_dig_count; i++) printf("-");
    printf("\n");

    int num2_count = count_digits(num2);

    for(int i = 0; i < num2_count; i++){
        int current_digit = take_digit(num2,i);
        printf("%*.0lf\n",product_dig_count-i,(double)current_digit*num1);
    }

    for(int i = 0; i < product_dig_count; i++) printf("-");
    printf("\n");
    printf("%*.0lf\n",product_dig_count,num1*num2);


    return 0;
}