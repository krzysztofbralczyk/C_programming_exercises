#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int set_union(const int first[], int size, const int second[], int size2, int dest[], int size3) {

	if (size <= 0 || size2 <= 0 || size3 <= 0) return -1;

	int firstCounter = 0, secondCounter = 0, destCounter = 0;
	int secondEnded = 0, firstEnded = 0;
	int firstTurnedOn = 1, secondTurnedOn = 1;

	while (!(firstCounter == size && secondCounter == size2)) {

		if (((first[firstCounter] < second[secondCounter]) || secondEnded) && firstTurnedOn) {
			if(destCounter < size3) dest[destCounter] = first[firstCounter];
			destCounter++;
			firstCounter++;
			if (firstCounter == size) {
				firstTurnedOn = 0;
				firstEnded = 1;
			}
		}
		else if (((second[secondCounter] < first[firstCounter]) || firstEnded) && secondTurnedOn) {
			if (destCounter < size3) dest[destCounter] = second[secondCounter];
			destCounter++;
			secondCounter++;
			if (secondCounter == size2) {
				secondTurnedOn = 0;
				secondEnded = 1;
			}
		}
		else if ((second[secondCounter] == first[firstCounter]) && secondTurnedOn && firstTurnedOn) {       //jesli natrafimy na takie same liczby

			int j = firstCounter;
			while (first[j] == first[j + 1] && j < size - 1) j++;
			int count1 = j - firstCounter + 1; //policz ile razy ta liczba wystepuje w wektorze 1

			int k = secondCounter;
			while (second[k] == second[k + 1] && k < size2 - 1) k++;
			int count2 = k - secondCounter + 1; //policz ile razy ta liczba wystepuje w wektorze 2

			int max = (count1 > count2) ? count1 : count2;

			for (int i = 0; i < max; i++) {
				if (destCounter < size3) dest[destCounter] = first[firstCounter];
				destCounter++;
			}

			for (int i = 0; i < count1; i++) {
				firstCounter++;
				if (firstCounter == size) {
					firstTurnedOn = 0;
					firstEnded = 1;
				}
			}

			for (int i = 0; i < count2; i++) {
				secondCounter++;
				if (secondCounter == size2) {
					secondTurnedOn = 0;
					secondEnded = 1;
				}
			}
		}
	}

	for (int i = 0; i < size - 1; i++) {
		if (first[i] > first[i + 1]) {
			//printf("pierwsze sprawdzenie wywalilo");
			return -1;
		}
	}
	for (int i = 0; i < size2 - 1; i++) {
		if (second[i] > second[i + 1]) {
			//printf("drugie sprawdzenie wywalilo");
			return -1;
		}
	}
	//if (!(is_sorted(first, size) && is_sorted(second, size2))) return -1;
	if (destCounter > size3) return -2;
	return destCounter;

}

int set_intersection(const int first[], int size, const int second[], int size2, int dest[], int size3) {
	if (size <= 0 || size2 <= 0 || size3 <= 0) return -1;

	int firstCounter = 0, secondCounter = 0, destCounter = 0;
	int secondEnded = 0, firstEnded = 0;
	int firstTurnedOn = 1, secondTurnedOn = 1;

	while (!(firstCounter == size && secondCounter == size2)) {

		if (((first[firstCounter] < second[secondCounter]) || secondEnded) && firstTurnedOn) {
			firstCounter++;
			if (firstCounter == size) {
				firstTurnedOn = 0;
				firstEnded = 1;
			}
		}
		else if (((second[secondCounter] < first[firstCounter]) || firstEnded) && secondTurnedOn) {
			secondCounter++;
			if (secondCounter == size2) {
				secondTurnedOn = 0;
				secondEnded = 1;
			}
		}
		else if ((second[secondCounter] == first[firstCounter]) && secondTurnedOn && firstTurnedOn) {       //jesli natrafimy na takie same liczby

			int j = firstCounter;
			while (first[j] == first[j + 1] && j < size - 1) j++;
			int count1 = j - firstCounter + 1; //policz ile razy ta liczba wystepuje w wektorze 1

			int k = secondCounter;
			while (second[k] == second[k + 1] && k < size2 - 1) k++;
			int count2 = k - secondCounter + 1; //policz ile razy ta liczba wystepuje w wektorze 2

			int min = (count1 < count2) ? count1 : count2;

			for (int i = 0; i < min; i++) {
				if (destCounter < size3) dest[destCounter] = first[firstCounter];
				destCounter++;
			}

			for (int i = 0; i < count1; i++) {
				firstCounter++;
				if (firstCounter == size) {
					firstTurnedOn = 0;
					firstEnded = 1;
				}
			}

			for (int i = 0; i < count2; i++) {
				secondCounter++;
				if (secondCounter == size2) {
					secondTurnedOn = 0;
					secondEnded = 1;
				}
			}
		}
	}

	for (int i = 0; i < size - 1; i++) {
		if (first[i] > first[i + 1]) return -1;
	}

	for (int i = 0; i < size2 - 1; i++) {
		if (second[i] > second[i + 1]) return -1;
	}

	if (destCounter > size3) return -2;
	return destCounter;
}

int set_difference(const int first[], int size, const int second[], int size2, int dest[], int size3) {

	if (size <= 0 || size2 <= 0 || size3 <= 0) return -1;

	int firstCounter = 0, secondCounter = 0, destCounter = 0;
	int secondEnded = 0, firstEnded = 0;
	int firstTurnedOn = 1, secondTurnedOn = 1;

	while (!(firstCounter == size && secondCounter == size2)) {

		if (((first[firstCounter] < second[secondCounter]) || secondEnded) && firstTurnedOn) {
			if (destCounter < size3) dest[destCounter] = first[firstCounter];
			destCounter++;
			firstCounter++;
			if (firstCounter == size) {
				firstTurnedOn = 0;
				firstEnded = 1;
			}
		}
		else if (((second[secondCounter] < first[firstCounter]) || firstEnded) && secondTurnedOn) {
			if (destCounter < size3) dest[destCounter] = second[secondCounter];
			destCounter++;
			secondCounter++;
			if (secondCounter == size2) {
				secondTurnedOn = 0;
				secondEnded = 1;
			}
		}
		else if ((second[secondCounter] == first[firstCounter]) && secondTurnedOn && firstTurnedOn) {       //jesli natrafimy na takie same liczby

			int j = firstCounter;
			while (first[j] == first[j + 1] && j < size - 1) j++;
			int count1 = j - firstCounter + 1; //policz ile razy ta liczba wystepuje w wektorze 1

			int k = secondCounter;
			while (second[k] == second[k + 1] && k < size2 - 1) k++;
			int count2 = k - secondCounter + 1; //policz ile razy ta liczba wystepuje w wektorze 2

			int mod = abs(count1 - count2);

			for (int i = 0; i < mod; i++) {
				if (destCounter < size3) dest[destCounter] = first[firstCounter];
				destCounter++;
			}

			for (int i = 0; i < count1; i++) {
				firstCounter++;
				if (firstCounter == size) {
					firstTurnedOn = 0;
					firstEnded = 1;
				}
			}

			for (int i = 0; i < count2; i++) {
				secondCounter++;
				if (secondCounter == size2) {
					secondTurnedOn = 0;
					secondEnded = 1;
				}
			}
		}
	}

	for (int i = 0; i < size - 1; i++) {
		if (first[i] > first[i + 1]) return -1;
	}

	for (int i = 0; i < size2 - 1; i++) {
		if (second[i] > second[i + 1]) return -1;
	}

	if (destCounter > size3) return -2;
	return destCounter;
}
int is_sorted(const int vec[], int size) {

	if (size <= 0) return -1;
	int not_decreasing = 1;
	for (int i = 0; i < size - 1; i++) {
		if (vec[i] > vec[i + 1]) not_decreasing = 0;
	}
	return not_decreasing;
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


int main() {

	int A[100] = {0};
	printf("Podaj wektor 1:\n");
	int counterA = read_vector(A, 100, 0);
	if (counterA == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterA < 1) {
		printf("not enough data available");
		return 2;
	}

	int B[100] = {0};
	printf("Podaj wektor 2:\n");
	int counterB = read_vector(B, 100, 0);
	if (counterB == -1) {
		printf("Incorrect input");
		return 1;
	}
	if (counterB < 1) {
		printf("not enough data available");
		return 2;
	}

	if (!is_sorted(A, counterA) || !is_sorted(B, counterB)) {
		printf("Incorrect input data");
		return 3;
	}

	int C[100] = {0};
	int counterC = set_union(A, counterA, B, counterB, C, 100);
	if (counterC == -2) printf("Output buffer is too small\n");
	else if (counterC == 0) printf("Nothing to show\n");
	else display_vector(C, counterC);

	int D[100] = {0};
	int counterD = set_intersection(A, counterA, B, counterB, D, 100);
	if (counterD == -2) printf("Output buffer is too small\n");
	else if (counterD == 0) printf("Nothing to show\n");
	else display_vector(D, counterD);

	int E[100] = {0};
	int counterE = set_difference(A, counterA, B, counterB, E, 100);
	if (counterE == -2) printf("Output buffer is too small\n");
	else if (counterE == 0) printf("Nothing to show\n");
	else display_vector(E, counterE);

	return 0;
}
