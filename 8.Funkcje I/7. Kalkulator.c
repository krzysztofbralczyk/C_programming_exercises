#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float a, float b){
  return a + b;
}
float subtract(float a, float b){
  return a - b;
}
float multiply(float a, float b){
  return a * b;
}
float divide(float a, float b){
  if(b!=0) return a / b;
  else return -1;
}

int main(){

  printf("\nArgument 1 please: "); 
  float num1;         
  if(!scanf("%f",&num1)){
    printf("Incorrect input");
    return 1;
  }
  
  printf("\nArgument 2 please: "); 
  float num2;         
  if(!scanf("%f",&num2)){
    printf("Incorrect input");
    return 1;
  }
  printf("Suma: %.1f\nRoznica: %.1f\nIloczyn: %.2f\n",add(num1,num2),subtract(num1,num2),multiply(num1,num2));
  if(num2!=0) printf("Iloraz: %.5f",divide(num1,num2));
  else printf("operation not permitted");
  return 0;
}


