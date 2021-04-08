#include <stdio.h>
#include "expected_prototypes.h"

int czy_pierwsza(int a){
  if(a <= 1) return 0;
  if(a == 2) return 1;
  for(int i = 2; i < a; i++){
    if(a % i == 0) return 0;
  }
  return 1;
}

int goldbach(int a){
  int no_goldbach = 1;
  for(int i = 2; i < a; i++){
    if(czy_pierwsza(i)){
      for(int j = 2; j < a; j++){
        if(czy_pierwsza(j)){
          if(i+j==a){
            printf("(%d, %d)",i,j);
            no_goldbach = 0;
          }
        }
      }
    }
  }
  if(no_goldbach || a % 2 != 0) return 0;
  else return 1;
}


int main(){

  printf("\nfirst: "); 
  int num1;       
  if(scanf("%d",&num1) != 1){
    printf("Incorrect input");
    return 1;
  }
  printf("\nsecond: "); 
  int num2;        
  if(scanf("%d",&num2) != 1){
    printf("Incorrect input");
    return 1;
  }
  if(num1>num2){
    printf("Incorrect input");
    return 1;
  }

  for(int i = num1; i <= num2; i++){
    if(i % 2 == 0){
      printf("%d: ",i);
      goldbach(i);
      printf("\n");
    }
  }
  
  return 0;
}


