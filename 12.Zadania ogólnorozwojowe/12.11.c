#include <stdio.h>
#include <math.h>

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

	return counter;
}


int reduce(int num, int aim){
    int ender = 9 * pow(10,aim-1) + pow(10,aim-1)-1;
    while(num > ender) num = num/10;
    return num % 10;
}

int count_digits(int num){
    int counter = 0;
    while(num >= 1){
        counter++;
        num = num/10;
    }
    return counter;
}

double concatenate(double num1, double num2){
    double pow = 10;
    while(num2 >= pow) pow *= 10;
    return num1 * pow + num2;
}

int second_number_has_first_different_digit_bigger(int num1, int num2){
    int smaller = (num1 < num2) ? num1 : num2;


    for(int i = 1; i <= count_digits(smaller); i++){
        int num1_reduced = reduce(num1,i);
        int num2_reduced = reduce(num2,i);
        if(num2_reduced > num1_reduced) return 1;
        if(num2_reduced < num1_reduced) return 0;
    }

    if(concatenate((double)num1,(double)num2) < concatenate((double)num2,(double)num1)){
        return 1;
    } else return 0;
    
}

int bubble_sort_desc(int tab[], int size){
	if(size < 1) return 1;
    int not_sorted = 1;
    while(not_sorted){
        not_sorted = 0;
        for(int i = 0; i < size-1; i++){
            if(second_number_has_first_different_digit_bigger(tab[i],tab[i+1])){
                int temp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = temp;
                not_sorted = 1;
            }
        }
    }
    return 0;
}


int main(){
    int numbers[1000];
    printf("Liczby do konkatenacji prosze:");
    int numbersCounter = read_vector(numbers,1000,0);

    if (numbersCounter == -1) {
        printf("Incorrect input");
        return 1;
    }

    if (numbersCounter < 1) {
        printf("Not enough data available");
        return 3;
    }

    bubble_sort_desc(numbers,numbersCounter);
    for(int i = 0; i < numbersCounter; i++) printf("%d",numbers[i]);


    return 0;
}