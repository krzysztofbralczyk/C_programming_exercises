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
    printf("%d ",i);
    for(int j = 0; j < 5; j++){
      int flag = 1;
      for(int k = 0; k < 5; k++){
        if(A[i][k] != B[k][j]){
          flag = 0;
          break;
        }
      }
      if(flag == 1){
        printf("%d ",j);
      }
    }
    printf("\n");
  }

  return 0;
}