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

int is_twin(int a, int b){
  if((b-a==2 || b-a ==-2) && is_prime(a) && is_prime(b)) return 1;
  else return 0;
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

  int no_twins = 1;
  for(int i = num1; i <= num2-2; i++){
    if(is_twin(i,i+2)){
      printf("%d, %d\n",i,i+2);
      no_twins = 0;
    }
  }
  if(no_twins){printf("Nothing to show");}
  
  return 0;
}


