#include <stdio.h>


char* trim(char* text);
char* reverse(char* text);
char* remove_non_letters(char* text);

int main() {
	printf("Podaj tekst: ");
	char strin[1001];
	scanf("%1000[^\n]", strin);
	char* strin_after = reverse(trim(remove_non_letters(strin)));
	// char* strin_after = trim(strin);
	if (*strin_after == '\0') {
		printf("wohs ot gnihtoN");
	}
	else printf("%s", strin_after);
	
	return 0;
}

char* trim(char* text) {
	if (text == NULL) return NULL;
	

	text = text + 1;
	int j = 0;
	while (*text) {
		int triggered = 0;
		if (*(text - 1) == ' ' && *text == ' ') {
			triggered = 1;
			int i = 0;
			while (*text) {
				*(text - 1) = *text;
				text++;
				i++;
			}
			*(text - 1) = *text;
			text = text - i;
		}
		if (!triggered) {
			text++;
			j++;
		}
	}
	if (*(text - 1) == ' '){
	*(text - 1) = *(text);
	}
	text = text - 1 - j;

	if(*text == ' '){
		int i = 0;
		while (*(text+1)) {
			*(text) = *(text+1);
			text++;
			i++;
		}
		*text = *(text+1);
		text = text - i;
	}
	return text;
}	
char* reverse(char* text) {
	if (text == NULL) return NULL;
	int length = 0;
	while (*text) {
		length++;
		text++;
	}
	text = text - length;

	for (int i = 0; i < length / 2; i++) {
		char temp = *(text + i);
		*(text + i) = *(text + length - i-1);
		*(text + length - i - 1) = temp;
	}
	return text;
}
char* remove_non_letters(char* text) {
	if (text == NULL) return NULL;
	int i = 0;
	while (*text) {
		if ((*text < 'a' || *text > 'z') && (*text < 'A' || *text > 'Z')) {
			*text = ' ';
		}
		text++;
		i++;
	}
	text = text - i;
	return text;
}	