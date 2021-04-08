#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

float poly(float a){
  return (5*a*a + (12.55)*a + 0.75);
}


int main(){

  printf("\nargument please: "); 

  float num1;        
  if(scanf("%f",&num1) != 1){
    printf("Incorrect input");
    return 1;
  }

  printf("Wynik: %.2f",poly(num1));
  
  return 0;
}


