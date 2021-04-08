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

void display_vector(const int vec[], int size) {
	if (size < 1) return;
	for (int i = 0; i < size; i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

int sort_odd_asc_even_desc(int tab[], int size);

int main()
{
    int A[150] = {0};
    printf("Podaj wektor:\n");
    int counterA = read_vector(A, 150, 0);
    if (counterA == -1) {
        printf("Incorrect input");
        return 1;
    }

    if (counterA < 1) {
        printf("Not enough data available");
        return 3;
    }

    int sort_result = sort_odd_asc_even_desc(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(A,counterA);
}

int sort_odd_asc_even_desc(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            // dwie parzyste
            if(tab[i+1] > tab[i] && tab[i] % 2 == 0 && tab[i+1] % 2 == 0){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
            // dwie nieparzyste
            else if(tab[i+1] < tab[i] && (tab[i] % 2 == 1 || tab[i] % 2 == -1) && (tab[i+1] % 2 == 1 || tab[i+1] % 2 == -1)){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
            // jedna parzysta druga nieparzysta
            else if((tab[i+1] % 2 == 1 || tab[i+1] % 2 == -1) && tab[i] % 2 == 0){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
        }
    }
    return 0;
}


