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
  int max_difference = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      for(int k = j+1;k < 5; k++){
        if(abs(A[j][i]-A[k][i]) > max_difference){
          max_difference = abs(A[j][i]-A[k][i]);
        }
      }
    }
  }

  for(int i = 0; i < 5; i++){
    int flag = 1;
    for(int j = 0; j < 5; j++){
      for(int k = j+1;k < 5; k++){
        if(flag && abs(A[j][i]-A[k][i]) == max_difference){
          printf("%d %d %d %d %d\n",A[0][i],A[1][i],A[2][i],A[3][i],A[4][i]);
          flag = 0;
        }
      }
    }
  }

  return 0;
}
