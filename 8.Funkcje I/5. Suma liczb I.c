#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int add(int a, int b){
  return a + b;
}

int main(){

  printf("\nArgument 1 please: "); 
  int num1;         
  if(!scanf("%d",&num1)){
    printf("Incorrect input");
    return 1;
  }
  
  printf("\nArgument 2 please: "); 
  int num2;         
  if(!scanf("%d",&num2)){
    printf("Incorrect input");
    return 1;
  }
  printf("\nWynik dodawania to: %d",add(num1,num2));

  return 0;
}


