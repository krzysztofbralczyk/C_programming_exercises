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

  for(int i = 0; i < counter; i++){       //dla kazdego elementu wektora
    printf("%d ",i);                      //druknij index wektora
    int found[200];                       //przygotuj tablice na indexy znalezionych kwadratow 
    int f_idx = 0;                        //przygotuj licznik dla powyzszej tablicy
    int f_counter = 0;                      //przygotuj/wyzeruj licznik znalezionych kwadratow

    for(int j = 0; j < 10; j++){          //iteruj przez wszystkie wiersze macierzy
      for(int k = 0; k < 10; k++){        //iteruj przez wszystkie kolumny macierzy
        if(A[j][k] == pow(vector[i],2)){  //jesli element macierzy jest rowny kwadratowi elementu wektora
          f_counter++;                      //podbij licznik znalezionych kwadratow o jeden
          found[f_idx] = k;               //zapisz index wiersza
          f_idx++;                        
          found[f_idx] = j;               //zapisz index kolumny
          f_idx++;
        }
      }
    }
    printf("%d ",f_counter);
    for(int j = 0; j < f_idx; j++){
      printf("%d ",found[j]);
    }
    printf("\n");
  }


  return 0;
}