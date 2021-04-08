#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
  int A[10][10];
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }

  int mini_counter = 0;
  int c; //current
  for(int i = 1; i < 9; i++){
    for(int j = 1; j < 9; j++){
      c = A[i][j];
      if(A[i-1][j-1]>c && A[i-1][j]>c && A[i-1][j+1]>c && A[i][j-1]>c && A[i][j+1]>c && A[i+1][j-1]>c && A[i+1][j]>c && A[i+1][j+1]>c) mini_counter++;
    }
  }

  if(!mini_counter){
    printf("Nothing to show");
    return 0;
  }
  printf("%d\n",mini_counter);

for(int i = 1; i < 9; i++){
    for(int j = 1; j < 9; j++){
      c = A[i][j];
      if(A[i-1][j-1]>c && A[i-1][j]>c && A[i-1][j+1]>c && A[i][j-1]>c && A[i][j+1]>c && A[i+1][j-1]>c && A[i+1][j]>c && A[i+1][j+1]>c){
        printf("%d %d\n",i,j);
      }
    }
  }


  return 0;
}