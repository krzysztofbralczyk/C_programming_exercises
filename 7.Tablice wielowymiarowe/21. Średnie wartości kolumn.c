#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
  int A[5][5];
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }
  int sum = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      sum+=A[j][i];
    }
    printf("%.2lf ",(double)sum/5);
    sum = 0;
  }

  return 0;
}
