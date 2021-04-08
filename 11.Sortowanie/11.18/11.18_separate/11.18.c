#include <stdio.h>
#include "vector_utils.h"
int freq_sort(int tab[], int size);

int main()
{
    int A[150] = {0};
    printf("Podaj wektor:\n");
    int counterA = read_vector(A, 150, -1);
    if (counterA == -1) {
        printf("Incorrect input");
        return 1;
    }

    if (counterA < 1) {
        printf("Not enough data available");
        return 3;
    }

    int sort_result = freq_sort(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(A,counterA);
}

int freq(int tab[], int size, int num){
    int counter = 0;
    for(int i = 0; i < size; i++) if (tab[i] == num) counter++;
    return counter;
}

int freq_sort(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(freq(tab,size,(tab[i+1])) > freq(tab,size,(tab[i]))){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            } else if(freq(tab,size,tab[i+1]) == freq(tab,size,tab[i])) {
                if(tab[i] > tab[i+1]){
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

