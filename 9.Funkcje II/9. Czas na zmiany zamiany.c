#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

// char my_toLower(char c){
//     if(c < 97) return c + 32;
//     return c;
// }

unsigned int my_strlen(const char tab[]) {
	int i = 0;
	while (tab[i] != '\0') i++;
	return i;
}

void replace(char tab[], char from, char to) {
	int i = 0;
	while (tab[i] != '\0') {
		if (tab[i] == from) {
			tab[i] = to;
		}
		i++;
	}

}
void replace_string(char tab[], const char from[], const char to[]) {
	if (my_strlen(from) < my_strlen(to)) return;
	int i = 0;
	while (tab[i] != '\0') {   // iteruj przez wszystkie wyrazy ciagu glownego
		int j = 0;
		int remember_starting_i = i;   //zapamietuj index elementu przy ktorym odpalana jest nastepna petla
		int found_whole_word = 1;
		while (tab[i] == from[j]) {      //gdy znajdziesz slowo do zamiany
			i++;
			j++;
			found_whole_word = 0;
			if (from[j] == '\0') {         //upewnij sie ze jest pelne i odpal zamiane
				found_whole_word = 1;
				i = remember_starting_i; //cofnij i do poczatku slowa ktore chcemy zamienic w glownym ciagu
				j = 0;                   //wyzeruj licznik
				while (to[j] != '\0') {    // iteruj do konca wyrazu na ktory zamieniamy
					tab[i] = to[j];
					i++;
					j++;
				}
				for (; from[j] != '\0'; j++) {     // iteruj tyle razy jaka jest dlugosc wyrazu ktory znika
					int remember_i = i;
					while (tab[i] != '\0') {
						tab[i] = tab[i + 1];       //ughhh, co za spaghetti
						i++;
					}
					i = remember_i;
				}
				i = remember_starting_i;
			}
		}
		if(found_whole_word) i++;
	}
}

int main() {
	printf("Ciag znakow prosze:  "); //input1
	char A[1001] = { 0 };
	scanf("%1000[^\n]", A);
	while (getchar() != '\n');

	char B[1001] = { 0 };
	char C[1001] = { 0 };
	for (int i = 0; A[i] != '\0'; i++) {
		B[i] = A[i];
		C[i] = A[i];
	}
	replace(B, 'a', 'a' + 1);
	replace(B, 'e', 'e' + 1);
	replace(B, 'u', 'u' + 1);
	replace(B, 'i', 'i' + 1);
	replace(B, 'o', 'o' + 1);
	replace(B, 'y', 'y' + 1);
    replace(B, 'A', 'A' + 1);
	replace(B, 'E', 'E' + 1);
	replace(B, 'U', 'U' + 1);
	replace(B, 'I', 'I' + 1);
	replace(B, 'O', 'O' + 1);
	replace(B, 'Y', 'Y' + 1);
    replace_string(C, "The", " ");
    replace_string(C, "THe", " ");
    replace_string(C, "THE", " ");
    replace_string(C, "ThE", " ");
    replace_string(C, "the", " ");
    replace_string(C, "tHe", " ");
    replace_string(C, "tHE", " ");
    replace_string(C, "thE", " ");
    
    

	for (int i = 0; B[i] != '\0'; i++) {
		printf("%c", B[i]);
	}
	printf("\n");
	for (int i = 0; C[i] != '\0'; i++) {
		printf("%c", C[i]);
	}

}
