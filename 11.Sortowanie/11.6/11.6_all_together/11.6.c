#include <stdio.h>
#include "direction.h"

int read_vector(int vec[], int size, int stop_value);
void display_vector(const int vec[], int size);
int quicksort_asc(int l, int r, int tab[], int tabSize);
int quicksort_desc(int l, int r, int tab[], int tabSize);
int quicksort(int tab[], int size, enum direction dir);



int main(){

    // int A[50] = {0};
	// printf("Podaj wektor:\n");
	// int counterA = read_vector(A, 50, 0);
	// if (counterA == -1) {
	// 	printf("Incorrect input");
	// 	return 1;
	// }
	// if (counterA < 1) {
	// 	printf("not enough data available");
	// 	return 3;
	// }

    // printf("Podaj kierunek:\n");
	// int direction;
	// if(!scanf("%d",&direction)){
	// 	printf("Incorrect input");
	// 	return 1;
	// }
	// if(direction != 1 && direction != 2){
	// 	printf("Incorrect input data");
	// 	return 2;
	// }
	// if(direction == 1) direction = ASCENDING;
	// if(direction == 2) direction = DESCENDING;


	// int sort_result = quicksort(A,counterA,direction);
    // if(sort_result == 1){
    //     printf("Incorrect input");
    //     return 1;
    // }
	// display_vector(A,counterA);

	int input_array[] = {9, 5, 2, 0, 3, 0, 3, 8, 7, 5, 3, 10, 8, 5}; 
	quicksort_asc(0,13,input_array,14);
	display_vector(input_array,14);
    return 0;
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

//lets try taking right value as pivot
//lets do it less effective way and search from left to right, not from both sides at the same time
int quicksort_asc(int l, int r, int tab[], int tabSize){
	if(tabSize < 1 || abs(r-l)+1 > tabSize || l > tabSize) return 1; //basecase blad
	if (l>=r) return 0;                          //basecase koniec sortowania
                                                              
	int pivot = r;               //zapisz piwot (index liczby najbardziej na prawo w danym zakresie)
	int i = l;                   //iterujemy of lewej
	while(pivot > i){
		while(tab[i] < tab[pivot]) i++; //znajdz index elementu wiekszego of pivota
		if(i < pivot){
			int temp = tab[pivot];          //zapisz wartosc pivota
			tab[pivot] = tab[i];            //wstaw znalezionowa wartosc na ostatnie mniejsce(miejsce pivota)
			tab[i] = tab[pivot-1];          //na miejsce znalezionej wartosci wstaw wartosc przedostatnia
			tab[pivot - 1] = temp;          //na przedsostatnie miejsce wstaw wartosc pivota
			pivot--;                        // zmien index pivota
		}
	}

	return quicksort_asc(l,pivot - 1,tab,tabSize) || quicksort_asc(pivot + 1,r,tab,tabSize);
}

int quicksort_desc(int l, int r, int tab[], int tabSize){
	iftabSize < 1 || abs(r-l)+1 > tabSize || l > tabSize) return 1; //basecase blad
	if (l>=r) return 0;                          //basecase koniec sortowania
                                                              
	int pivot = r;               //zapisz piwot (index liczby najbardziej na prawo w danym zakresie)
	int i = l;                   //iterujemy of lewej
	while(pivot > i){
		while(tab[i] > tab[pivot]) i++; //znajdz index elementu wiekszego of pivota
		if(i < pivot){
			int temp = tab[pivot];          //zapisz wartosc pivota
			tab[pivot] = tab[i];            //wstaw znalezionowa wartosc na ostatnie mniejsce(miejsce pivota)
			tab[i] = tab[pivot-1];          //na miejsce znalezionej wartosci wstaw wartosc przedostatnia
			tab[pivot - 1] = temp;          //na przedsostatnie miejsce wstaw wartosc pivota
			pivot--;                        // zmien index pivota
		}
	}

	return quicksort_desc(l,pivot - 1,tab,tabSize) || quicksort_desc(pivot + 1,r,tab,tabSize);
}

int quicksort(int tab[], int size, enum direction dir){
	if(dir == ASCENDING){

		int ret_value = quicksort_asc(0,size-1,tab,size);
		return ret_value;

	} else if(dir == DESCENDING){

		int ret_value = quicksort_desc(0,size-1,tab,size);
		return ret_value;
        
	}
    return 1;
}