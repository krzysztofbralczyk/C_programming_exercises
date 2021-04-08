#include <stdio.h>
#include "types_utils.h"
#include "vector_utils.h"
#include "quicksort.h"



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


	int sort_result = quicksort(A,counterA,direction);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }
	display_vector(A,counterA);

    return 0;
}