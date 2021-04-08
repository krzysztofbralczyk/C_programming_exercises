#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int equal(const int first[], int size, const int second[], int size2){
    if(size<1 || size2 <1) return -1;

    if(size!=size2) return 0;

    for(int i = 0; i < size; i++){
        if(first[i] != second[i]) return 0;
    }
    return 1;
}
int copy(int dest[], int size, const int src[], int size2){
    if(size<1 || size2 <1) return -1;

    int counter = 0;
    int smaller = (size<size2)?size:size2;
    for(int i = 0; i < smaller; i++){
        dest[i] = src[i];
        counter++;
    }
    return counter;
}
void reverse(int first[], int size){
    for(int i = 0; i < size/2; i++){
        int temp = first[i];
        first[i] = first[size-1-i];
        first[size-1-i] = temp;
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


int main(){
    int A[100] = {0};
	printf("Podaj wektor A:   ");
	int counterA = read_vector(A, 100, -1);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 2) {
		printf("not enough data available");
		return 2;
	}

    int B[100] = {0};
    int counterB = copy(B,100,A,counterA);
    if(counterB == -1){
        printf("Incorrect input");
        return 1;
    }
    reverse(B,counterB);
    int a = equal(A,counterA,B,counterB);
    if(a == -1) {
        printf("Incorrect input");
        return 1;
    } else if (a == 1){
        printf("TAK");
    } else 
        printf("NIE");

    return 0;
}
