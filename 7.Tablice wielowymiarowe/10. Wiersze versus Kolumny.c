#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
  int A[10][10];
  int biggest = 0;
  int flag = 1;
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
      if(flag){
        if(A[i][j]%2==0){
          biggest = A[i][j];
          flag = 0;
        }
      }
      if(A[i][j]%2==0){
        if(A[i][j] > biggest){
          biggest = A[i][j];
        }
      }
    }
  }

  if(flag){
    printf("nothing to show");
    return 0;
  }

  printf("\n");
  int sum=0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(A[i][j] == biggest){
        sum = 0;
        printf("%d %d ",j,i);
        for(int k = 0;k < 10;k++){
          sum+=A[i][k];
          sum-=A[k][j];
        }
        printf("%d\n",sum);
      } 
    }
  }
  return 0;
}