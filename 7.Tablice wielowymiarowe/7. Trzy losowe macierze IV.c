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
     printf("%3d ",A[i][j]);
   }
   printf("\n");
  }
  printf("\n");
  
  for(int i = 0; i < 4; i++){
   for(int j = 0; j < 4; j++){
     printf("%3d ",B[i][j]);
   }
   printf("\n");
  }
  printf("\n");
  
  for(int i = 0; i < 4; i++){
   for(int j = 0; j < 4; j++){
     printf("%3d ",C[i][j]);
   }
   printf("\n");
  }
  printf("\n");
  
  int sum = 0;
  for(int i = 0; i < 4; i++){
    sum = 0;
    for(int j = 0; j < 4; j++){
      sum+=A[i][j];
    }
    printf("%3d ",sum);
  }
  printf("\n");

  for(int i = 0; i < 4; i++){
    sum = 0;
    for(int j = 0; j < 4; j++){
      sum+=A[j][i];
    }
    printf("%3d ",sum);
  }
  printf("\n");

  for(int i = 0; i < 4; i++){
    sum = 0;
    for(int j = 0; j < 4; j++){
      sum+=B[i][j];
    }
    printf("%3d ",sum);
  }
  printf("\n");

  for(int i = 0; i < 4; i++){
    sum = 0;
    for(int j = 0; j < 4; j++){
      sum+=B[j][i];
    }
    printf("%3d ",sum);
  }
  printf("\n");

  for(int i = 0; i < 4; i++){
    sum = 0;
    for(int j = 0; j < 4; j++){
      sum+=C[i][j];
    }
    printf("%3d ",sum);
  }
  printf("\n");

  for(int i = 0; i < 4; i++){
    sum = 0;
    for(int j = 0; j < 4; j++){
      sum+=C[j][i];
    }
    printf("%3d ",sum);
  }
  printf("\n");
//LOGIC END

  return 0;
}