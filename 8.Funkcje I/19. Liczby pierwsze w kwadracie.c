#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_prime(int a){
  if(a <= 1) return 0;
  if(a == 2) return 1;
  for(int i = 2; i < a; i++){
    if(a % i == 0) return 0;
  }
  return 1;
}


int main(){

  int A[5][5];
  printf("Wingardium Lewiosa!:\n");

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }

  int max_p = 0;
  for(int i = 1; i < 4; i++){
    for(int j = 1; j < 4; j++){

      int p_counter = 0;
      for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
          if(is_prime(A[k][l])){
            p_counter++;
          }
        }
      }

      if(p_counter>max_p){
        max_p = p_counter;
      }
    }
  }
  if(max_p==0){
    printf("0");
    return 0;
  }
  
  int s_counter = 0;
  for(int i = 1; i < 4; i++){
    for(int j = 1; j < 4; j++){

      int p_counter = 0;
      for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
          if(is_prime(A[k][l])){
            p_counter++;
          }
        }
      }

      if(p_counter==max_p){
        s_counter++;
      }
    }
  }
  printf("%d\n",s_counter);


  for(int i = 1; i < 4; i++){
    for(int j = 1; j < 4; j++){
      int p_counter = 0;
      for(int k = i-1; k <= i+1; k++){
        for(int l = j-1; l <= j+1; l++){
          if(is_prime(A[k][l])){
            p_counter++;
          }
        }
      }
      if(p_counter==max_p){
        printf("%d %d\n",i,j);
      }
    }
  }

  return 0;
}
