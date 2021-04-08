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

  int B[2][2];
  printf("TEKST ZACHETY2!!!!!!!!:\n");
  for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      if(!scanf("%d",&B[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }

  int counter = 0;
  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(A[i][j]==B[0][0] && A[i][j+1]==B[0][1] && A[i+1][j]==B[1][0] && A[i+1][j+1]==B[1][1]){
        counter++;
      }
    }
  }
  printf("%d\n",counter);

  for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
      if(A[i][j]==B[0][0] && A[i][j+1]==B[0][1] && A[i+1][j]==B[1][0] && A[i+1][j+1]==B[1][1]){
        printf("%d %d\n",j,i);
      }
    }
  }

  return 0;
}
// -7 2 7 8 0 -3 2 -10 -8 3 
// 3 5 2 -2 8 -1 -1 0 -4 7 
// 1 -7 4 -2 3 7 -8 2 3 1 
// 10 -6 -10 5 -8 7 -5 4 -6 0 
// 0 10 1 10 4 -4 3 4 7 4 
// 1 3 -9 0 6 9 -6 -10 5 -4 
// 4 3 5 -7 -8 7 6 -3 -2 -5 
// -10 -10 -10 10 10 3 9 -2 10 9 
// -6 0 -5 8 5 -4 6 -6 9 10 
// 9 -7 3 -8 0 -6 -6 9 10 -10 

// 5 -4 
// 0 -6 