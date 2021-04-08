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


  int c; //current
  int biggest_sum;
  int flag = 1;
  for(int i = 0; i < 5; i++){ // dla kazdego wiersza
    for(int j = 0; j < 5; j++){ // dla kazdego elementu
      c = A[i][j];                // zapisz obecna wartosc
      for(int k = j+1; k<5; k++){   // i dla pozostalych elementow danego wiersza
        if(flag){
          biggest_sum = c + A[i][k];
          flag = 0;
        }
        if(biggest_sum < c + A[i][k]){biggest_sum = c + A[i][k];}
      }
      for(int l = i+1; l < 5; l++){  // i dla pozostalych wierszy
        for(int m = 0; m < 5; m++){       // dla pozostalych elementow
          if(flag){
            biggest_sum = c + A[m][l];
            flag = 0;
          }
          if(biggest_sum < c + A[l][m]){biggest_sum = c + A[l][m];}
        }
      }
    }
  }
  printf("%d ",biggest_sum);
  
  int biggest_sum_counter = 0;
  int biggest_sums[1500] = {0};
  int biggest_sum_idx = 0;
  for(int i = 0; i < 5; i++){ // dla kazdego wiersza
    for(int j = 0; j < 5; j++){ // dla kazdego elementu
      c = A[i][j];                // zapisz obecna wartosc
      for(int k = j+1; k<5; k++){   // i dla pozostalych elementow danego wiersza
        if(biggest_sum == c + A[i][k]){
          biggest_sum_counter++;
          biggest_sums[biggest_sum_idx] = i;
          biggest_sum_idx++;
          biggest_sums[biggest_sum_idx] = j;
          biggest_sum_idx++;
          biggest_sums[biggest_sum_idx] = i;
          biggest_sum_idx++;
          biggest_sums[biggest_sum_idx] = k;
          biggest_sum_idx++;
        }
      }
      for(int l = i+1; l < 5; l++){  // i dla pozostalych wierszy
        for(int m = 0; m < 5; m++){       // dla pozostalych elementow
          if(biggest_sum == c + A[l][m]){
            biggest_sum_counter++;
            biggest_sums[biggest_sum_idx] = i;
            biggest_sum_idx++;
            biggest_sums[biggest_sum_idx] = j;
            biggest_sum_idx++;
            biggest_sums[biggest_sum_idx] = l;
            biggest_sum_idx++;
            biggest_sums[biggest_sum_idx] = m;
            biggest_sum_idx++;
          }
        }
      }
    }
  }
  printf("%d\n",biggest_sum_counter);
  for(int i = 0; i < biggest_sum_idx; i++){
    printf("%d ",biggest_sums[i]);
    if(i%4==3 && i!=0){
      printf("\n");
    }
  }




  return 0;
}