#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[]) {
	int i = 0;
	while (tab[i] != '\0') i++;
	return i;
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



int find_longest_word(const char tab[]){
	int result = -1;
	int max_length = 0;

	for(int i = 0; tab[i] != '\0'; i++){
		int remember_starting_index = i;
		while((tab[i] >= 'a' && tab[i] <= 'z') || (tab[i] >= 'A' && tab[i] <= 'Z')){
			i++;
		}
		if((i - remember_starting_index) > max_length){
			result = remember_starting_index;
			max_length = i - remember_starting_index;
		} 
	}
	return result;
}
int get_word_length(const char tab[], int start){
	int length = 0;
	for(;tab[length]!='\0';length++);
	if (start > length) return -1;

	int counter = 0;
	for(int i = start; (tab[i] >= 'a' && tab[i] <= 'z') || (tab[i] >= 'A' && tab[i] <= 'Z'); i++) counter++;
	if(counter == 0) return -1;
	return counter;
}


int main(){

	printf("Ciag znakow prosze:  "); //input1
	char A[1001] = {'\0'};
	scanf("%1000[^\n]", A);
	while (getchar() != '\n');

	int idx_of_longest_word = find_longest_word(A);
	if(idx_of_longest_word == -1){
		printf("Nothing to show");
		return 0;
	}
	

	//to bedzie bez sensu poniewaz zadanie wymaga by uzyc replace_string. ta funkcja oryginalnie sluzyla do zamiany wszystkich wystapien danego ciagu
	// a w tym zadaniu powinno sie zamieniac pojedyncze wystapienie ciagu ( bo musimy wydrukowac ten sam wyraz kilka razy jesli kilka razy wystepuje w tekscie)
	// jednoczesnie nie moge zmienic replace string lub nieuzyc replace string bo nie przejde testu jednostkowego lub wyskoczy mi Clang

	while(idx_of_longest_word != -1){
		idx_of_longest_word = find_longest_word(A);
		int length = get_word_length(A,idx_of_longest_word);   // mamy index i dlugosc najdluzszego slowa

		char B[1001] = {'\0'};
		int idx_B = 0;

		for(int i = idx_of_longest_word; i < idx_of_longest_word + length; i++){   //mamy zapisane najdluzsze slowo
			B[idx_B] = A[i];
			idx_B++;
		}
		int counter = 0; //potrzebne by dobrze sformatowac newline'y
		for(int i = 0; A[i] != '\0'; i++){          //drukujemy zapisane najdluzsze slowo tyle razy ile znajdziemy je w tekscie
			int j = 0;
			while (A[i] == B[j]) {
				i++;
				j++;
			}
			if (B[j] == '\0') {
				if(counter > 0) printf("\n");
				for(int k = 0; B[k] != '\0'; k++){
					printf("%c",B[k]);
				}
				counter++;
			}
		}
		printf("\n");
		replace_string(A,B," ");
	}
    return 0;
}
