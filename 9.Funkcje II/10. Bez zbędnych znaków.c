#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int my_strlen(const char tab[]) {
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

void lstrip(char tab[]){
    while(tab[0] == ' '){
        for(int j = 0; tab[j] != '\0'; j++){
            tab[j] = tab[j+1];
        }
    }
}

void rstrip(char tab[]){
    int i = my_strlen(tab)-1;
    while (tab[i] == ' '){
        i--;
        if(i==-1) break;
    }
    tab[i+1] = '\0';
}

void strip(char tab[]){
    rstrip(tab);
    lstrip(tab);
}
int double_exists(char tab[],char c){
    int i = 1;
    while(tab[i] != '\0'){
        if(tab[i] == c && tab[i-1] == c) return 1;
        i++;
    }
    return 0;
}

int main(){
    printf("Ciag znakow prosze:  "); //input1
	char A[1001] = { 0 };
	scanf("%1000[^\n]", A);
	while (getchar() != '\n');
    
    char B[1001] = { 0 };
	char C[1001] = { 0 };
    char D[1001] = { 0 };
    char E[1001] = { 0 };

	for (int i = 0; A[i] != '\0'; i++) {
		B[i] = A[i];
		C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
	}
    lstrip(B);
    rstrip(C);
    strip(D);
    

    for(int i = '!'; i < '0'; i++){
        replace(E,i,' ');
    }
    for(int i = ':'; i < 'A'; i++){
        replace(E,i,' ');
    }
    for(int i = '['; i < 'a'; i++){
        replace(E,i,' ');
    }
    for(int i = '{'; i <= '~'; i++){
        replace(E,i,' ');
    }
    strip(E);
    while(double_exists(E, ' ')) replace_string(E,"  "," ");

    for (int i = 0; B[i] != '\0'; i++) {
		printf("%c", B[i]);
	}
    printf("\n");

    for (int i = 0; C[i] != '\0'; i++) {
		printf("%c", C[i]);
	}
    printf("\n");
    
    for (int i = 0; D[i] != '\0'; i++) {
		printf("%c", D[i]);
	}
    printf("\n");
    
    for (int i = 0; E[i] != '\0'; i++) {
		printf("%c", E[i]);
	}
    return 0;
}
