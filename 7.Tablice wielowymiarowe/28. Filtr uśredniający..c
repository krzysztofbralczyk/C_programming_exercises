#include <stdio.h>

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
  float B[8][8];
  double sum = 0;
  for(int i = 1; i < 9; i++){
    for(int j = 1; j < 9; j++){
      sum = 0;
      for(int k = i-1; k<=i+1; k++){
        for(int l = j-1; l <= j+1; l++){
          sum += A[k][l];
          B[i][j] = (double)sum/9; //added
        }
      }
    //   printf("%.2lf ",(double)sum/9); //deleted
    }
    // printf("\n"); //deleted
  }

    for(int i = 1; i < 9; i++){ //added
         for(int j = 1; j < 9; j++){
          printf("%.2lf ",B[i][j]);
        }
        printf("\n");
    }
  return 0;
}
