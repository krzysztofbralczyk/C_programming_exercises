#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[]) {
	int i = 0;
	while (tab[i] != '\0') i++;
	return i;
}
int my_atoi(const char tab[]) {
	int tab_length = my_strlen(tab);
	int res = 0;
	int num = 1;
	for (int i = 0; i < tab_length; i++) {
		if (i == 0 && tab[i] == '-') {
			num = -1;  //jesli na pierwszym miejscu jest minus 
			continue;  //to zmien wynik na ujemny i przejdz do nastepnej iteracji
		}
		if ((tab[i] < '0' || tab[i] > '9') && res == 0) return 0;
		if ((tab[i] < '0' || tab[i] > '9') && res != 0) break;
		res = res * 10 + tab[i] - '0';
	}
	return num * res;
}
float my_atof(const char tab[]) {
	int tab_length = my_strlen(tab);
	double res = 0.0;
	int num = 1;
	int secondCycle = 0;
	int i = 0;
	for (i = 0; i < tab_length; i++) {
		if (tab[i] == '.' && i != 0) {
			secondCycle = 1;
			i++;
			break;
		}

		if (i == 0 && tab[i] == '-') {
			num = -1;  //jesli na pierwszym miejscu jest minus 
			continue;  //to zmien wynik na ujemny i przejdz do nastepnej iteracji
		}

		if ((tab[i] < '0' || tab[i] > '9') && res == 0) return 0;
		if ((tab[i] < '0' || tab[i] > '9') && res != 0) break;
		res = res * 10 + tab[i] - '0';
	}

	if (secondCycle) {
		double divider = 10.0;
		for (; i < tab_length; i++) {
			res += (double)(tab[i] - (double)'0') / divider;
			divider *= 10.0;
		}
	}
	return num * (float)res;
}


int main() {
	printf("input prosze: ");

	char liczba[16];
	scanf("%15[^\n]", liczba);
	while (getchar() != '\n');


	printf("%d\n%d\n%.4f", (int)my_strlen(liczba), my_atoi(liczba), my_atof(liczba));

	return 0;
}
