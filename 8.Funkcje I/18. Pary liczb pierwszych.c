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
  int counter = 0;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(is_prime(A[i][j])){
        for(int k = i; k <= i+1; k++){
          for(int l = j-1; l <= j+1; l++){
            if(k>=0 && k < 5 && l >=0 && l < 5 && !(k==i && l==j) && !(k==i && l<j)){
              if(is_prime(A[k][l])){
                counter++;
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n",counter);

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(is_prime(A[i][j])){
        for(int k = i; k <= i+1; k++){
          for(int l = j-1; l <= j+1; l++){
            if(k>=0 && k < 5 && l >=0 && l < 5 && !(k==i && l==j) && !(k==i && l<j)){
              if(is_prime(A[k][l])){
                printf("%d %d %d %d\n",i,j,k,l);
              }
            }
          }
        }
      }
    }
  }
  
  return 0;
}


