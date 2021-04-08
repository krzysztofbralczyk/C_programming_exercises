#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

float add(float a, float b){
  return a + b;
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
  printf("\nWynik dodawania to: %.1f",add(num1,num2));

  return 0;
}


