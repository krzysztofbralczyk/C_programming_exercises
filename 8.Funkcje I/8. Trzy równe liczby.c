#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int compare(int a, int b, int c){
  if(a==b && b==c) return 1;
  else return 0;
}


int main(){

  printf("\n3 arguments please: "); 
  
  int num1, num2 ,num3;         
  if(scanf("%d-%d-%d",&num1,&num2,&num3) != 3){
    printf("Incorrect input");
    return 1;
  }

  if(compare(num1,num2,num3)) printf("EQUAL");
  else printf("NOT EQUAL");
  
  return 0;
}


