#include <stdio.h>
#include "vector_utils.h"

int sort_by_length(int tab[], int size);

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

    int sort_result = sort_by_length(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(A,counterA);
}

int length(int num){
    int size = 0;
    if(num < 0) size++;

    while(num != 0){
        num = num / 10;
        size++;
    }

    return size;
}

int sort_by_length(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(length(tab[i+1]) < length(tab[i])){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            } else if(length(tab[i+1]) == length(tab[i])){
                if(tab[i] < tab[i+1]){
                    int temp = tab[i];
                    tab[i] = tab[i+1];
                    tab[i+1] = temp;
                    not_sorted = 1;
                }
            }
        }
    }

    return 0;
}

