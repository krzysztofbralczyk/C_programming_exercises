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
  // while ( getchar() != '\n' );
  int x2;
  printf("\nPodaj liczbę wyrazów szegegu Taylora: ");   
  if(scanf("%d",&x2) != 1){
    printf("Incorrect input");
    return 1;
  }
  if(x2<0){
    printf("Incorrect input");
    return 1;
  }
  // while ( getchar() != '\n' );
  printf("%lf %lf",mySin(x1,x2),myCos(x1,x2));

  return 0;
}
