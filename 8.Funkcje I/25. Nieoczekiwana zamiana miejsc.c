#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

void swap_vector(int first[], int size, int second[], int size2){
    int bigger_size = (size>size2)?size:size2;
    for(int i = 0; i < bigger_size; i++){
        int temporary_var = first[i];
        first[i] = second[i];
        second[i] = temporary_var;
    }
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
	printf("Podaj wektor A:   ");
	int counterA = read_vector(A, 50, 0);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("Not enough data available");
		return 2;
	}

    int B[50] = {0};
	printf("Podaj wektor B:   ");
	int counterB = read_vector(B, 50, 0);
	if (counterB == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterB < 1) {
		printf("not enough data available");
		return 2;
	}
    
    swap_vector(A,counterA,B,counterB);

    display_vector(A,counterB);
    display_vector(B,counterA);

    return 0;
}
