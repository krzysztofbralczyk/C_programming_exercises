#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main()
{
//INPUT START
  int matrix[5][5];
  printf("Zachecam: \n");
  for(int i = 0; i < 5; i++){
    for(int j = 0; j< 5; j++){
      if(!scanf("%d",&matrix[i][j])){
        printf("Incorrect input");      //ERROR HANDLING1
        return 1;
      }
    }
  }
//INPUT END

//LOGIC START
int temp;
 for(int i = 0; i < 5; i++){
   for(int j = 0; j < 5; j++){
     if(i == j){
       temp = matrix[i][j];
       matrix[i][j] = matrix[i][4-j];
       matrix[i][4-j] = temp;
     }
     printf("%4d",matrix[i][j]);
   }
   printf("\n");
  }
//LOGIC END

  return 0;
}