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

  int B[5][5];
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(!scanf("%d",&B[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(A[i][j]>B[i][j]){
        printf("%d ",A[i][j]);
      } else {
        printf("%d ",B[i][j]);
      }
    }
    printf("\n");
  }


  return 0;
}