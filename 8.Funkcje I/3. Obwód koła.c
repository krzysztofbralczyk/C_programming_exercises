#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

float circumference(float b){\
  if(b <= 0) return -1;
  return M_PI*b;
}

int main(){

  printf("\nArgument please: "); 

  float num;         

  if(!scanf("%f",&num)){       
    printf("Incorrect input");
    return 1;
  }

  float result = circumference(num);
  if(result == -1){       
    printf("Incorrect input");
    return 1;
  }
  printf("\nResult is: %.4f", result);

}


