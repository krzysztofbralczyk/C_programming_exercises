#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

float quadratic_equation(float a, float b, float c, float x){
  return a*x*x + b*x + c;
}


int main(){

  printf("\nequation please: "); 
  float num1,num2,num3;        
  if(scanf("%fx^2%fx%f",&num1,&num2,&num3) != 3){
    printf("Incorrect input");
    return 1;
  }

  printf("\nx please: "); 
  float num4;        
  if(scanf("%f",&num4) != 1){
    printf("Incorrect input");
    return 1;
  }
  

  printf("Wynik: %.2f",quadratic_equation(num1,num2,num3,num4));
  
  return 0;
}


