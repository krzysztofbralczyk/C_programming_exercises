#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

int main()
{
  int A[7][7];
  printf("TEKST ZACHETY!!!!!!!!:\n");
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      if(!scanf("%d",&A[i][j])){
        printf("\nincorrect input");
        return 1;
      }
    }
  }

  int num;
  int counter = 0;
  int vector[4];
  printf("Wektora poprosza:\n");
  if(!scanf("%d",&num)){
    printf("Incorrect input");
    return 1;    
  }
  while(num != 0 && counter<4){
    vector[counter] = num;
    counter++;
    
    if(!scanf("%d",&num)){
      printf("Incorrect input");
      return 1;
    } 
  }
  if(counter < 1){
    printf("not enough data available");
    return 2;
  }

  int v_counter = 0;
  int found_vectors[300];
  int fv_counter = 0;

for(int i = 0; i < 7-counter+1; i++){
    for(int j = 0; j < 7; j++){

      int flag = 1;
      for(int k = 0; k < counter; k++){
        if(vector[k] != A[i+k][j]){
          flag = 0;
          break;
        }
      }
      if(flag == 1){
        v_counter++;
        found_vectors[fv_counter] = 1;
        fv_counter++;
        found_vectors[fv_counter] = j;
        fv_counter++;
        found_vectors[fv_counter] = i;
        fv_counter++;
      }
    }
  }

  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7-counter+1; j++){

      int flag = 1;
      for(int k = 0; k < counter; k++){
        if(vector[k] != A[i][j+k]){
          flag = 0;
          break;
        }
      }
      if(flag == 1){
        v_counter++;
        found_vectors[fv_counter] = 2;
        fv_counter++;
        found_vectors[fv_counter] = j;
        fv_counter++;
        found_vectors[fv_counter] = i;
        fv_counter++;
      }
    }
  }
  printf("%d\n",v_counter);
  for(int i = 0; i < fv_counter; i++){
    printf("%d ",found_vectors[i]);
    if(i % 3 == 2) printf("\n");
  }




  return 0;
}