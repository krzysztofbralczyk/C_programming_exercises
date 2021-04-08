#include <stdio.h>

char* swap_order_words(char* txt);
char* trim(char* text);
char* remove_non_letters(char* text);
char* reverse(char* text);
char* my_strcat(char* dest, const char* src);
int my_strlen(const char* str);

int main(){
    printf("Podaj tekst: ");
	char strin[1001];
	scanf("%1000[^\n]", strin);

	swap_order_words(strin);
	if(*strin == '\0'){
		my_strcat(strin,"Nothing to show");
		swap_order_words(strin);
	} 
	printf("%s",strin);
    return 0;
}

char* swap_order_words(char* txt){
	if(txt == NULL) return NULL;
    reverse(trim(remove_non_letters(txt)));

	int previous = 0;
	for(int i = 0; *(txt+i); i++){

		if(*(txt+i) == ' '){
			*(txt+i) = '\0';
			reverse(txt+previous);
			*(txt+i) = ' ';
			previous = i+1;
		}
	}
	reverse(txt+previous);
	return txt;
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
		*(text + i) = *(text + length - i - 1);
		*(text + length - i - 1) = temp;
	}
	return text;
}

char* my_strcat(char* dest, const char* src){
    int dest_len = my_strlen(dest);
    int src_len = my_strlen(src);
    for(int i = 0; i <= src_len; i++){ // <= to include terminator
        *(dest + dest_len + i) = *(src + i);
    }
    return dest;
}

int my_strlen(const char* str){
    int length = 0;
    while(*(str+length)) length++;
    return length;
}