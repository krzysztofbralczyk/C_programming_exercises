#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_int(const char tab[]) {
	int  i = 0;

	while (tab[i] != '\0') {
		if ((tab[i] > '9' || tab[i] < '0') && (!(i == 0 && tab[i] == '-'))) return 0;
		i++;
	}

	return 1;
}

int is_hexa(const char tab[]) {
	int  i = 0;
	while (tab[i] != '\0') {
		if ((tab[i] > '9' || tab[i] < '0') && tab[i] != 'A' && tab[i] != 'B' && tab[i] != 'C' && tab[i] != 'D' && tab[i] != 'E' && tab[i] != 'F' && tab[i] != 'a' && tab[i] != 'b' && tab[i] != 'c' && tab[i] != 'd' && tab[i] != 'e' && tab[i] != 'f') return 0;
		i++;
	}
	return 1;
}

int is_float(const char tab[]) {
	int i = 0;                    //głowny iterator

	if (tab[0] == '-') i++;        //jeśli na pierwszym miejscu minus, to przewiń go
	if (tab[i] < '0' || tab[i] > '9') return 0; //jesli pierwszy element po za minusem nie jest liczba, zwroc NIE

	while (tab[i] != '.') {           //przewijaj do poki nie trafisz na kropke
		if (tab[i] == '\0') return 0;               //jesli natrafisz na koniec , zwroc NIE (bo nie bylo kropki) <to jest chyba redundantne z ponizszym>
		if (tab[i] < '0' || tab[i] > '9') return 0; //jesli element nie jest liczba, zwroc NIE        
		i++;                                       // przewin do przodu
	}     //jesli program sie nie zakonczyl to obecnym elementem jest kropka

	while (tab[i] != 'e' && tab[i] != 'E') { //przewijaj do poki nie trafisz na e lub E
        i++;
		if (tab[i] == '\0') return 1;               //jesli natrafisz na koniec , zwroc TAK (znalezlismy liczbe dziesietna)
		if ((tab[i] < '0' || tab[i] > '9') && tab[i]!='e' && tab[i] != 'E') return 0; //jesli element nie jest liczba lub e, zwroc NIE
	}     //jesli program sie nie skonczyl to obecnym elementem jest e lub E

	if (tab[i + 1] != '+' && tab[i + 1] != '-') return 0; //jesli po e/E nie ma plusa i nie ma minusa, zwroc NIE
	i += 2;  //przewin do pierwszego elementu po plusie

	while (tab[i] != '\0') {    //przewijaj do konca liczby
		if (tab[i] < '0' || tab[i] > '9') return 0;    //jesli trafisz na cos co nie jest liczba, zwroc NIE
		i++;
	}
	return 1;

}




int main() {
	printf("Ciag znakow prosze:  "); //input1
	char A[101] = { 0 };
	scanf("%100[^\n]", A);
	while (getchar() != '\n');

	if (is_int(A)) printf("TAK\n");
	else printf("NIE\n");

	if (is_float(A)) printf("TAK\n");
	else printf("NIE\n");

	if (is_hexa(A)) printf("TAK\n");
	else printf("NIE\n");



	return 0;
}
