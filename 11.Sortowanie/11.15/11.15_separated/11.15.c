#include <stdio.h>
#include "vector_utils.h"

int sort_odd_desc(int tab[], int size);
int sort_even_asc(int tab[], int size);

int main(){
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

    int sort_result = sort_odd_desc(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    sort_result = sort_even_asc(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(A,counterA);
}

int sort_odd_desc(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 1; i < size-2; i+=2){
            if(tab[i+2] > tab[i]){
                int temp = tab[i];
                tab[i] = tab[i+2];
                tab[i+2] = temp;
                not_sorted = 1;
            }
        }
    }

    return 0;
}
int sort_even_asc(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-2; i+=2){
            if(tab[i+2] < tab[i]){
                int temp = tab[i];
                tab[i] = tab[i+2];
                tab[i+2] = temp;
                not_sorted = 1;
            }
        }
    }

    return 0;
}