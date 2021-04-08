#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sqr(int a){
  return a*a;
}

int main(){

  printf("\nArgument please: ");
  int num;
  if(!scanf("%d",&num)){
    printf("Incorrect input");
    return 1;
  }
  printf("\nResult is: %d",sqr(num));

}


