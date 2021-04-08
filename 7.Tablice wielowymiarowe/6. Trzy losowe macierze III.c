#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
//INPUT START
  int A[4][4];
  int B[4][4];
  int C[4][4];

  srand(time(0));
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      A[i][j] = rand()%101;
    }
  }

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      B[i][j] = rand()%101;
    }
  }

  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(i==j)C[i][j] = 1;
      else C[i][j] = 0;
    }
  }
//INPUT END

//LOGIC START
 for(int i = 0; i < 4; i++){
   for(int j = 0; j < 4; j++){
     printf("%4d ",A[i][j]);
   }
   printf("\n");
  }
  printf("\n");
  
 for(int i = 0; i < 4; i++){
   for(int j = 0; j < 4; j++){
     printf("%4d ",B[i][j]);
   }
   printf("\n");
  }
  printf("\n");
  
 for(int i = 0; i < 4; i++){
   for(int j = 0; j < 4; j++){
     printf("%4d ",C[i][j]);
   }
   printf("\n");
  }
  printf("\n");

  int sum = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        sum += A[i][k] * B[k][j];
      }
      printf("%5d ",sum);
      sum = 0;
    }
    printf("\n");
  }
  printf("\n");

  sum = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        sum += B[i][k] * A[k][j];
      }
      printf("%5d ",sum);
      sum = 0;
    }
    printf("\n");
  }
  printf("\n");

  sum = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        sum += A[i][k] * C[k][j];
      }
      printf("%5d ",sum);
      sum = 0;
    }
    printf("\n");
  }
  printf("\n");

  sum = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        sum += C[i][k] * A[k][j];
      }
      printf("%5d ",sum);
      sum = 0;
    }
    printf("\n");
  }
  printf("\n");
//LOGIC END

  return 0;
}