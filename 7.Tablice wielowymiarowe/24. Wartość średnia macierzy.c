#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
  int A[5][5];
  int sum = 0;
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
      sum += A[i][j];
    }
  }
  // printf("%d\n",sum);

  double smallest_difference = 999999;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(fabs((float)A[i][j] - (float)sum/25) < smallest_difference){
        smallest_difference = fabs((float)A[i][j] - (float)sum/25);
      }
    }
  }
  // printf("%d\n",smallest_difference);

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(fabs((float)A[i][j] - (float)sum/25) == smallest_difference){
        printf("%d %d\n",i,j);
      }
    }
  }

  return 0;
}
