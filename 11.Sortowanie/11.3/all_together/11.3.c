#include <stdio.h>
#include "direction.h"

int find_min_idx(int tab[], int size,int start_idx){
    int min = tab[start_idx];
    int min_idx = start_idx;
    for(int i = start_idx; i < size; i++){
        if(tab[i] < min){
            min = tab[i];
            min_idx = i;
        } 
    }
    return min_idx;
}
int find_max_idx(int tab[], int size,int start_idx){
    int max = tab[start_idx];
    int max_idx = start_idx;
    for(int i = start_idx; i < size; i++){
        if(tab[i] > max){
            max = tab[i];
            max_idx = i;
        } 
    }
    return max_idx;
}

int selection_sort_asc(int tab[], int size){
    if(size < 1) return 1;

    for(int i = 0; i < size - 1; i++){
        int idx_of_min_value = find_min_idx(tab,size,i);
        int temp = tab[i];
        tab[i] = tab[idx_of_min_value];
        tab[idx_of_min_value] = temp;
        display_vector(tab,size);
    }
	display_vector(tab,size);
    return 0;
}
int selection_sort_desc(int tab[], int size){
    if(size < 1) return 1;

    for(int i = 0; i < size - 1; i++){
        int idx_of_max_value = find_max_idx(tab,size,i);
        int temp = tab[i];
        tab[i] = tab[idx_of_max_value];
        tab[idx_of_max_value] = temp;
        display_vector(tab,size);
    }
	display_vector(tab,size);
    return 0;
}
int selection_sort(int tab[], int size, enum direction dir){
    
    if(dir == ASCENDING){

		int ret_value = selection_sort_asc(tab,size);
		return ret_value;

	} else if(dir == DESCENDING){

		int ret_value = selection_sort_desc(tab,size);
		return ret_value;
        
	}
    return 1;
}

int read_vector(int vec[], int size, int stop_value) {
	if (size < 1) return -1;
	int num, counter = 0;

	do {
		if (!scanf("%d", &num)) { return -1; }
		if (num != stop_value) {
			vec[counter] = num;
			counter++;
		}
	} while (num != stop_value && counter < size);

	while ( getchar() != '\n' );

	return counter;
}

void display_vector(const int vec[], int size) {
	if (size < 1) return;
	for (int i = 0; i < size; i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

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


	int sort_result = selection_sort(A, counterA, direction);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    return 0;
}