#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
//INPUT START
  int A[15][15];
  int counters[30] = {0};
  printf("TEKST ZACHETY!!!!!!!!:\n");
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
      if(A[i][j]<0 || A[i][j]>=30){
        printf("\nvalue out of range");
        return 2;
      }
      counters[A[i][j]]++;
    }
  }
  printf("\n");
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
      printf("%d ",counters[A[i][j]]);
    }
    printf("\n");
  }

//INPUT END

//LOGIC END

  return 0;
}