#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int count_string(const char tab[], const char tab2[]) {
	int counter = 0;
	int i = 0;
	while (tab[i] != '\0') {
		int j = 0;
        int broken = 0;
		while (tab[i] == tab2[j]) {
			i++;
			j++;
			if (tab2[j] == '\0') {
				counter++;
                broken = 1;
				break;
			}
		}
		if(!broken) i++;
	}
	return counter;
}

int count_all_of(const char tab[], const char tab2[]) {
	int counter = 0;
	int i = 0;

	while (tab[i] != '\0') {              //petla skanujaca wszystkie litery ciagu 1
		int j = 0;
		while (tab2[j] != '\0') {          //petla skanujaca wszystkie litery ciagu 2
			if (tab[i] == tab2[j]) {              //jesli ciag 2 ma taka sama litere jak ciag 1
				int unique = 1;
				for (int k = j - 1; k >= 0; k--) {            //petla szukajaca czy ciag 2 ma druga taka sama litere jak obecnie sprawdzana
					if (tab2[k] == tab2[j]) {           //jesli tak to litera nie jest unikalna
						unique = 0;
						break;
					}
				}
				if (unique) counter++;
			}
			j++;
		}
		i++;
	}

	return counter;
}


int count(const char tab[], char c) {
	int i = 0;
	int counter = 0;
	while (tab[i] != '\0') {
		if (tab[i] == c) {
			counter++;
		}
		i++;
	}
	return counter;
}

int main() {

	printf("Ciag znakow prosze:  "); //input1
	char A[1001] = { 0 };
	scanf("%1000[^\n]", A);
	while (getchar() != '\n');

	printf("Drugi ciag znakow prosze:  "); //input2
	char B[1001] = { 0 };
	scanf("%1000[^\n]", B);
	while (getchar() != '\n');

	printf("%d\n%d\n%d", count(A, B[0]), count_string(A, B), count_all_of(A, B));

	return 0;
}
