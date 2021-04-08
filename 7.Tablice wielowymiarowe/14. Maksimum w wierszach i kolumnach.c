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
  int biggest;
  for(int i = 0; i < 5; i++){
    biggest = A[i][0];
    for(int j = 1; j < 5; j++){
      if(A[i][j]>biggest)biggest = A[i][j];
    }
    printf("%d ",biggest);
  }

  for(int i = 0; i < 5; i++){
    biggest = A[0][i];
    for(int j = 1; j < 5; j++){
      if(A[j][i]>biggest)biggest = A[j][i];
    }
    printf("%d ",biggest);
  }

  return 0;
}