#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int unique(int first[], int size){
    if (size < 1) return -1;
    int counter = size;
    for(int i = 0; i < counter-1; i++){
        while(first[i] == first[i+1] && counter > 1){
            for(int j = i + 1; j < counter-1; j++){
                first[j] = first[j+1];
            }
            counter--;
        }
    }
    return counter;
}
int adjacent_find(const int first[], int size){
    if (size < 1) return -1;
    for(int i = 0; i < size-1; i++){
        if(first[i] == first[i+1]){
            return i;
        }
    }
    return -2;

}
int mismatch(const int first[], int size, const int second[], int size2, int out[2]){
    if(size < 1 || size2 < 1) return -1;
    int smaller = (size<size2)?size:size2;
    int counter = 0;
    for(int i = 0; i < smaller; i++){
        if(first[i]!=second[i]){
            out[0] = first[i];
            out[1] = second[i];
            return i;
        }
        counter++;
    }
    if(size==size2) {
        out[0] = 0;
        out[1] = 0;
        return counter;
    } else if (size>size2){
        out[0] = first[smaller];
        out[1] = 0;
        return smaller;
    } else{
        out[0] = 0;
        out[1] = second[smaller];
        return smaller;
    }
    

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
	printf("Podaj wektor A:   ");
	int counterA = read_vector(A, 100, 0);
	if (counterA == -1) {                         //input
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("not enough data available");        //error handling1
		return 2;
	}

    int B[100] = {0};
    int counterB = copy(B,100,A,counterA);                     //copy
    if(counterB == -1){
        printf("Incorrect input");
        return 1;
    }

    counterB = unique(B,counterB);
    if(counterB == -1){
        printf("Incorrect input");                        //error handilng2
        return 1;
    }

    display_vector(B,counterB);                               //display unique

    int adjacent = adjacent_find(A,counterA);                 //adjacent

    if(adjacent == -1){
        printf("Incorrect input");                        //error handilng3
        return 1;
    }

    printf("%d\n",adjacent);                               //display adjacent

    int out[2] = {0};
    int first_mismatched = mismatch(A,counterA,B,counterB,out);           //mismatch

    if(first_mismatched == -1){
        printf("Incorrect input");                                  //error handilng4
        return 1;
    }

    printf("%d %d %d",first_mismatched,out[1],out[0]);                       //display mismatched 


    return 0;
}
