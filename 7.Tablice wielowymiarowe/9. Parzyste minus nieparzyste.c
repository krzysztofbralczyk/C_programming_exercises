#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{

//INPUT START
  int A[10][10];
  int sum = 0;
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
      if((i+j) % 2 == 0) sum+=A[i][j];
      else sum-=A[i][j];
    }
  }
  printf("\n");

      printf("%d",sum);

//INPUT END



  return 0;
}