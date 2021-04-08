#include <stdio.h>
#include "vector_utils.h"

int bubble_sort(int tab[], int size){
    if(size < 1) return 1;
    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(tab[i+1] < tab[i]){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
        }
        display_vector(tab,size);
    }
    return 0;
}

int main (){

    int A[150] = {0};
	printf("Podaj wektor:\n");
	int counterA = read_vector(A, 150, 0);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("not enough data available");
		return 3;
	}

    int sort_result = bubble_sort(A,counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }
    return 0;
}