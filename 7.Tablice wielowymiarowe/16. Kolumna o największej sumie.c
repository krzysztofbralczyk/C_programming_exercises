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
  int biggest_sum;
  int flag = 1;
  for(int i = 0; i < 5; i++){
    sum = 0;
    for(int j = 0; j < 5; j++){
      sum += A[j][i];
    }
    if(flag){
      biggest_sum = sum;
      flag = 0;
    }
    if(sum > biggest_sum){biggest_sum = sum;}
  }

  for(int i = 0; i < 5; i++){
    sum = 0;
    for(int j = 0; j < 5; j++){
      sum += A[j][i];
    }
    if(sum == biggest_sum){
      printf("%d %d %d %d %d\n", A[0][i], A[1][i], A[2][i], A[3][i], A[4][i]);
    }
  }

  return 0;
}