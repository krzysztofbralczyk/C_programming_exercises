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

// biggest sum finding start
  int biggest_sum = -999999;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 8; j++){
      if((A[i][j]+A[i][j+1]+A[i][j+2]) > biggest_sum){
        biggest_sum = (A[i][j]+A[i][j+1]+A[i][j+2]);
      }
      if((A[j][i]+A[j+1][i]+A[j+2][i]) > biggest_sum){
       biggest_sum = (A[j][i]+A[j+1][i]+A[j+2][i]);
      }
    }
  }
// biggest sum finding end

  printf("%d\n",biggest_sum);

// biggest sum counter start
  int counter = 0;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 8; j++){
      if((A[i][j]+A[i][j+1]+A[i][j+2]) == biggest_sum){
        counter++;
      }
      if((A[j][i]+A[j+1][i]+A[j+2][i]) == biggest_sum){
        counter++;
      }
    }
  }
// biggest sum counter end

  printf("%d\n",counter);

// indexes printing start
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 8; j++){
      if((A[i][j]+A[i][j+1]+A[i][j+2]) == biggest_sum){
        printf("2 %d %d\n",i,j);
      }
    }
  }
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 8; j++){
      if((A[j][i]+A[j+1][i]+A[j+2][i]) == biggest_sum){
        printf("1 %d %d\n",j,i);
      }
    }
  }
// indexes printing end
  return 0;
}
// 77 26 -70 -43 14 73 -62 83 -19 26 
// -60 -25 -84 98 -97 22 -12 10 -36 84 
// -75 -38 8 86 44 -60 7 -23 88 80 
// -46 -17 30 96 97 -76 -98 -98 -49 -86 
// 95 5 -19 38 60 27 -60 29 -4 75 
// -8 -81 -12 85 81 24 79 -50 31 -84 
// -70 -52 -93 34 98 -23 -59 -7 94 66 
// -17 -35 64 -68 -82 48 67 94 -80 6 
// 24 -33 24 -41 39 -38 10 -47 36 11 
// -3 30 97 -37 16 -30 -84 -42 -95 26 