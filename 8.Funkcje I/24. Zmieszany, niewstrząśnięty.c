#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

void shuffle(int tab[], int size){
    static unsigned int call_count = 0;
    srand(call_count + time(0));
    call_count++;
    for(int i = 0; i < size; i++){

        int a = rand()%(size);
        int temp = tab[i];
        tab[i] = tab[a];
        tab[a] = temp;

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
    int A[100] = {0};

	printf("Podaj wektor:   ");

	int counterA = read_vector(A, 100, 0);

	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}

	if (counterA < 1) {
		printf("Not enough data available");
		return 2;
	}
    
    shuffle(A,counterA);

    display_vector(A,counterA);

    return 0;
}
