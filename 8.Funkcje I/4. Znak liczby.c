#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sign(int a){
  return (a>0)-(a<0);
}

int main(){

  printf("\nArgument please: "); 
  int num;         
  int correct = scanf("%d",&num);
  switch(2*sign(num)+correct){
    case -1:
      printf("negative");
    break;

    case 1:
      printf("zero");
    break;

    case 3:
      printf("positive");
    break;

    default:
    printf("Incorrect input");
    return 1;
  }

  return 0;
}


