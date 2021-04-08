#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


double mySin(double x, int n){
  double sum = 0;
  for(int k = 0; k <= n; k++){
    int silnia = 1;
    for(int i = 1; i <=2*k+1; i++){
      silnia *= i;
    }     
    sum += (pow(-1,k)/silnia*pow(x,2*k+1));
  }
  if(n<0) return -1;
  return sum;
}

double myCos(double x, int n){
  double sum = 0;
  for(int k = 0; k <= n; k++){
    int silnia = 1;
    for(int i = 1; i <=2*k; i++){
      silnia *= i;
    }
    sum += (pow(-1,k)/silnia*pow(x,2*k));
  }
  if(n<0) return -1;
  return sum;
}


int main(){

  printf("\nPodaj wartosc kata: "); 
  double x1;      
  if(scanf("%lf",&x1) != 1){
    printf("Incorrect input");
    return 1;
  }

  int x21 = 0;
  int x22 = 0;
  while(fabs(mySin(x1,x21)-sin(x1))>=0.0001){
    x21++;
  }

  while(fabs(myCos(x1,x22)-cos(x1))>=0.0001){
    x22++;
  }
  printf("%d\n%d",x21,x22);
  return 0;
}
