#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_prime(int a){
  if(a <= 1) return 0;
  if(a == 2) return 1;
  for(int i = 2; i < a; i++){
    if(a % i == 0) return 0;
  }
  return 1;
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

  int no_primes = 1;
  for(int i = num1; i <= num2; i++){
    if(is_prime(i)){
      printf("%d ",i);
      no_primes = 0;
    }
  }
  if(no_primes){printf("Nothing to show");}
  
  return 0;
}


