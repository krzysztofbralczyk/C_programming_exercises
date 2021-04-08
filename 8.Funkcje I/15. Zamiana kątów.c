#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

float toRadian(float a){
  return a*M_PI/180;
}
float toDegree(float a){
  return a/M_PI*180;
}


int main(){

  printf("\nkierunek konwersji: "); 
  int a;      
  if(scanf("%d",&a) != 1){
    printf("Incorrect input");
    return 1;
  }
  if(a!=1 && a!=2){
    printf("Incorrect input");
    return 1;
  }
  // while ( getchar() != '\n' );

  float b;
  printf("\nmiara kąta: ");   
  if(scanf("%f",&b) != 1){
    printf("Incorrect input");
    return 1;
  }

  if(a==1) printf("Wynik: %.2f",toRadian(b));
  else printf("Wynik: %.2f",toDegree(b));

  
  return 0;
}
