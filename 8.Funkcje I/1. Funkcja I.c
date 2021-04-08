#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"

int test1(int a){
  return a;
}


int main()
{
  int num;
  printf("number plase:\n");
  if(!scanf("%d",&num)){
    printf("Incorrect input");
    return 1;
  }
  printf("Wynik funkcji: %d",test1(num));
}
