#include <stdio.h>

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

int is_palindrom_rec(const int tab[], int start_index, int end_index){
    if(start_index < 0 || end_index < 0) return -1;
    if(tab[start_index] != tab[end_index]) return 0;
    if(start_index >= end_index) return 1;
    else return is_palindrom_rec(tab,start_index+1,end_index-1);
}

int main(){

    int A[100] = {0};
	printf("Podaj wektor A:   ");
	int counterA = read_vector(A, 100, -1);
	if (counterA == -1) {                      
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("not enough data available");     
		return 2;
	}
    int res_of_is_palin = is_palindrom_rec(A,0,counterA-1);

    if(res_of_is_palin == -1){
        printf("Incorrect input");
        return 1;
    }

    if(res_of_is_palin) printf("YES");
    else printf("NO");
 
    return 0;
}