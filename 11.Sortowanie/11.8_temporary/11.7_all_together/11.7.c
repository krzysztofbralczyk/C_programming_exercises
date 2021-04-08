#include <stdio.h>
#include "types_utils.h"

int bubble_sort_asc_rec(int tab[], int size);
int bubble_sort_desc_rec(int tab[], int size);
int bubble_sort_rec(int tab[], int size, enum direction dir);

int main(){
    int A[50] = {0};
	printf("Podaj wektor:\n");
	int counterA = read_vector(A, 50, 0);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("not enough data available");
		return 3;
	}

    printf("Podaj kierunek:\n");
	int direction;
	if(!scanf("%d",&direction)){
		printf("Incorrect input");
		return 1;
	}
	if(direction != 1 && direction != 2){
		printf("Incorrect input data");
		return 2;
	}
	if(direction == 1) direction = ASCENDING;
	if(direction == 2) direction = DESCENDING;


	// int sort_result = quicksort(A,counterA,direction);
    // if(sort_result == 1){
    //     printf("Incorrect input");
    //     return 1;
    // }
	// display_vector(A,counterA);

    return 0;
}

int find_idx_of_max(int arr[], int size){
    if(size - 1 == 0) return size - 1;
    else{
        int a = find_idx_of_max(arr,size-1);
        return ((arr[a]>arr[size-1]) ? a : size-1);
    }
}

int bubble_sort_asc_rec(int tab[], int size){
	if (size < 0) return 1;
	if (size - 1 < 0) return 0;
	int idx_of_max = find_idx_of_max(tab,size);
	int temp = tab[size - 1];
	tab[size - 1] = tab[idx_of_max];
	tab[idx_of_max] = temp;
	
}