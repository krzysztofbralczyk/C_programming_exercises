#include <stdio.h>

void totally_unnecessary_function_i_use_to_cover_my_lack_of_understanding_of_recursion(int n){
    if(n==0) return;
    else {
        printf("* ");
        totally_unnecessary_function_i_use_to_cover_my_lack_of_understanding_of_recursion(n-1);
    }
}

void rectangular_triangle(int n){
    if(n < 0) return;
    if(n == 0) return;
    rectangular_triangle(n-1);
    totally_unnecessary_function_i_use_to_cover_my_lack_of_understanding_of_recursion(n);
    printf("\n");
}

int main(){

    printf("Dlugosc podstawy prosze: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(num < 1){
        printf("Incorrect input data");
        return 2;
    }

    rectangular_triangle(num);
    return 0;
}