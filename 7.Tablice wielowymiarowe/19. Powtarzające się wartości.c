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

  int current;
  int duplicate;
  
  

  for(int i = 0; i < 5; i++){         // dla kazdej kolumny w macierzy A
    int commons[5] = {0};             // stworz tablice na wspolne elementy z kolumn macierzy A i B
    int c_indexer = 0; 
    for(int j = 0; j < 5; j++){       // dla kazdego elementu w danej kolumnie w macierzy A
      current = A[j][i];              // zapamietaj obecna wartosc w macierzy A
      for(int k = 0; k < 5; k++){     // dla kazdego elementu macierzy B
        if(current == B[k][i]){       // jesli zapamietana, obecna wartosc z macierzy A jest rowna wartosci z macierzy B
          duplicate = 0;                   // zaloz ze wartosci nie ma juz w tablicy commons
          for(int c = 0; c < c_indexer; c++){ 
            if(current == commons[c]){     // sprawdz czy wartosc jest w tablicy commons
              duplicate = 1;               // jesli tak, oznacz ze wartosc jest duplikatem
              break;                       // i nie sprawdzaj reszty tablicy commons
            }
          }
          if(!duplicate){                  // jesli wartosc nie jest duplikatem
            commons[c_indexer] = current;  // dodaj wartosc do tablicy commons
            c_indexer++;                   // i zwieksz index tablicy commons
          }
        }
      }
    }
    printf("%d ", c_indexer);
    if(c_indexer == 0){
      printf("\n");
    }else{
      for(int i = 0; i < c_indexer; i++){
        printf("%d ",commons[i]);
      }
      printf("\n");
    }
  }


  return 0;
}