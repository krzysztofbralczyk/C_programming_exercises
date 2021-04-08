#include <stdio.h>
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

int sort_positives(int tab[], int size){
    int not_sorted = 0;
    for(int i = 0; i < size-1; i++){
        if(tab[i] >= 0){
            for(int j = i+1; j < size; j++){
                if(tab[j] >= 0){
                    if(tab[i] < tab[j]){
                        int temp = tab[i];
                        tab[i] = tab[j];
                        tab[j] = temp;
                        not_sorted = 1;
                    }
                }
            }
        }
    }
    return not_sorted;
}

void sort_positives_desc(int tab[], int size){
    int not_sorted = 1;
    while(not_sorted){
        not_sorted = sort_positives(tab,size);
    }
}

int sort_negatives(int tab[], int size){
    int not_sorted = 0;
    for(int i = 0; i < size-1; i++){
        if(tab[i] < 0){
            for(int j = i+1; j < size; j++){
                if(tab[j] < 0){
                    if(tab[i] > tab[j]){
                        int temp = tab[i];
                        tab[i] = tab[j];
                        tab[j] = temp;
                        not_sorted = 1;
                    }
                }
            }
        }
    }
    return not_sorted;
}

void sort_negatives_asc(int tab[], int size){
    int not_sorted = 1;
    while(not_sorted){
        not_sorted = sort_negatives(tab,size);
    }
}


int sort_negative_asc_positive_desc(int tab[], int size){
    if(size < 1) return 1;
    sort_positives_desc(tab,size);
    sort_negatives_asc(tab,size);
    return 0;
}

