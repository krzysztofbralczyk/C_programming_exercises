#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

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

int vector_difference(const int first[], int size, const int second[], int size2, int dst[], int size3){
	if(size <= 0 || size2 <= 0 || size3 <= 0) return -1;
	int dst_counter = 0;
	for(int i = 0; i < size; i++){
		int is_duplicate = 0;
		for(int j = 0; j < size2; j++){
			if(first[i] == second[j]){
				is_duplicate = 1;
				break;
			}
		}
		if(!is_duplicate){
			if(dst_counter >= size3) return -1;
			dst[dst_counter] = first[i];
			dst_counter++;
		}
	}
	return dst_counter;
}

int random_vector(const int src[], int size, int dst[], int size2){
	if(size2 < size || size2 <= 0 || size <= 0) return -1;

	static int call_count = 0;
	srand(time(0) + call_count);
	call_count++;


	int counter = 0;
	for(int i = 0; i < size; i++){
		dst[i] = src[rand()%size];
		// printf("%d ",dst[i]);
		counter++;
	}
	// printf(" %d ",counter);
	return counter;
}


int main(){

    int A[150] = {0};
	printf("Podaj wektor A:   ");
	int counterA = read_vector(A, 150, 0);
	// printf("%d",counterA);

	if (counterA == -1) {                   
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("Not enough data available");    
		return 2;
	}

	int B[150] = {0};
	int counterB = random_vector(A,counterA,B,150);
	// printf("%d", counterB);

	if(counterB == -1){
		printf("Incorrect input");
		return 1;
	}

	int C[149] = {0};
	int counterC = vector_difference(A,counterA,B,counterB,C,149);
	// printf(" %d ",counterC);

	if(counterC == -1){
		printf("Incorrect input");
		return 1;
	}

	

	display_vector(B,counterB);

	if(counterC < 1){
		printf("Nothing to show");
		return 0;
	}
	
	display_vector(C,counterC);


    return 0;
}
