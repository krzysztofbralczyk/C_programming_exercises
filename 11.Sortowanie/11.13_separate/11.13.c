#include <stdio.h>
#include <stdlib.h>
#include "vector_utils.h"

int sort_negative_asc_positive_desc(int tab[], int size);

int main()
{
    int A[150] = {0};
    printf("Podaj wektor:\n");
    int counterA = read_vector(A, 150, 0);
    if (counterA == -1) {
        printf("Incorrect input");
        return 1;
    }

    if (counterA < 1) {
        printf("Not enough data available");
        return 3;
    }

    int sort_result = sort_negative_asc_positive_desc(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(A,counterA);
}

int sort_negative_asc_positive_desc(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            // dwie pozytywne
            if(tab[i+1] > tab[i] && tab[i] >= 0 && tab[i+1] >= 0){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
            // dwie negatywne
            else if(tab[i+1] < tab[i] && tab[i] < 0 && tab[i+1] < 0){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
            // jedna pozytywna jedna negatywna
            else if(tab[i+1] < 0 && tab[i] >= 0){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
        }
    }
    return 0;
}