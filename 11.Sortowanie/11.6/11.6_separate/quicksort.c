#include "quicksort.h"
#include <stdlib.h>

//lets try taking right value as pivot
//lets do it less effective way and search from left to right, not from both sides at the same time
int quicksort_asc(int l, int r, int tab[], int tabSize){
	if(tabSize < 1 || abs(r-l)+1 > tabSize || l > tabSize) return 1; //basecase blad
	if (l >= r) return 0;                          //basecase koniec sortowania
                                                              
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
	if(tabSize < 1 || abs(r-l)+1 > tabSize || l > tabSize) return 1; //basecase blad
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