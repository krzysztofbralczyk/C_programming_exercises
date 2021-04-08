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

  int B[5][5];
  printf("TEKST ZACHETY!!!!!!!!:\n");

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(!scanf("%d",&B[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }
  printf("\n");

  int C[5][5];
  for(int i = 0; i < 5; i++){         // dla kazdej kolumny w macierzy A 
    int sum1 = 0; int sum2 = 0;       // przygotuj zmienne na sumy kolumn macierzy A i B
    for(int j = 0; j < 5; j++){       // dla kazdego elementu w danej kolumnie w macierzy A i B
      sum1 += A[j][i];
      sum2 += B[j][i];
    }
    if(sum1>=sum2){
      for(int k = 0; k < 5; k++){
        C[k][i] = A[k][i];
      }
    }
    else{
      for(int k = 0; k < 5; k++){
        C[k][i] = B[k][i];
      }
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }


  return 0;
}