#include <stdio.h>
#include "direction.h"
#include "vector_utils.h"


int bubble_sort_asc(int tab[], int size){
    if(size < 1) return 1;
    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(tab[i+1] < tab[i]){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
        }
        display_vector(tab,size);
    }
    return 0;
}

int bubble_sort_desc(int tab[], int size){
	if(size < 1) return 1;
    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(tab[i+1] > tab[i]){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
        }
        display_vector(tab,size);
    }
    return 0;
}

int bubble_sort(int tab[], int size, enum direction dir){

	if(dir == ASCENDING){

		int ret_value = bubble_sort_asc(tab,size);
		return ret_value;

	} else if(dir == DESCENDING){

		int ret_value = bubble_sort_desc(tab,size);
		return ret_value;
        
	}

    return 1;
}