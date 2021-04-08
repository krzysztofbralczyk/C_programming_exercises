#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int my_strlen(const char tab[]) {
	int i = 0;
	while (tab[i] != '\0') i++;
	return i;
}

int starts_with(const char tab[], const char tab2[]) {
	int i = 0;
	while (tab[i] == tab2[i]){
        i++;
        if (tab2[i] == '\0') return 1;
    } 
	return 0;
}
int ends_with(const char tab[], const char tab2[]) {
	int lenght_of_tab2 = my_strlen(tab2);
	int lenght_of_tab = my_strlen(tab);
	for (int i = lenght_of_tab2 - 1, j = lenght_of_tab - 1; i >= 0 && j >= 0; i--, j--) {
		if (tab2[i] != tab[j]) return 0;
	}
	return 1;
}



int main()
{
	printf("Ciag znakow prosze:  ");
	char A[101] = { 0 };
	scanf("%100[^\n]", A);
	while (getchar() != '\n');

	printf("Ciag znakow prosze:  ");
	char B[101] = { 0 };
	scanf("%100[^\n]", B);
	while (getchar() != '\n');

	printf("start %d\nend %d", starts_with(A, B), ends_with(A, B));

}
