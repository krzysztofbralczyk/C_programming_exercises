#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_palindrom(const int tab[], int size, int start_index, int end_index){
    if(start_index >= end_index-1 || start_index < 0 || end_index > size){return -1;} //error handling
    int j = 0;
    for(int i = start_index; i <end_index; i++){
        if(!(tab[i] == tab[end_index-1-j])){return 0;}
        j++;
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
	// printf("\n");
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

    int max_length = 0;
    for(int i = 0; i < counterA-1; i++){
        for(int j = i+1; j < counterA; j++){
            if(is_palindrom(A,counterA,i,j+1)){
                if(j-i+1 > max_length) max_length = j-i+1;
            }
        }
    }
    if(max_length==0){
      printf("nothing to show");
      return 0;
    } 
    printf("%d\n",max_length);
    

    int B[100] = {0};
    int counterB = 0;
    int palindrom_counter = 0;
    for(int i = 0; i < counterA-1; i++){
        for(int j = i+1; j < counterA; j++){
            if(is_palindrom(A,counterA,i,j+1)){
                if(j-i+1 == max_length){
                    palindrom_counter++;
                    B[counterB] = i;
                    counterB++; 
                } 
            }
        }
    }
    printf("%d\n",palindrom_counter);
    display_vector(B,counterB);




    return 0;
}
