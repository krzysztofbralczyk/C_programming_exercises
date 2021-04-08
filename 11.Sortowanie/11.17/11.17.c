#include <stdio.h>

int sort_by_dividers(int tab[], int size);

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

    int sort_result = sort_by_dividers(A, counterA);
    if(sort_result == 1){
        printf("Incorrect input");
        return 1;
    }

    display_vector(A, counterA);
}

int dividers(int num){
    if(num == 0) return 0;

    int counter = 0;

    if(num < 0) num = -num;
    
    for(int i = 1; i < num+1; i++){
        if(num % i == 0) counter++;
    }
    return counter;
}

int sort_by_dividers(int tab[], int size){
    if(size < 1) return 1;

    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(dividers(tab[i+1]) < dividers(tab[i])){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            } else if(dividers(tab[i+1]) == dividers(tab[i])){
                if(tab[i] > tab[i+1]){
                    int temp = tab[i];
                    tab[i] = tab[i+1];
                    tab[i+1] = temp;
                    not_sorted = 1;
                }
            }
        }
    }

    return 0;
}

