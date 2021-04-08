#include <stdio.h>
int message_compression(char* txt);
void remove_non_letters(char* text);
void capitalize(char* text);
int delete_spacebars(char* text);

int main(){
    printf("Podaj tekst: ");
    char strin1[1001];   
    scanf("%1000[^\n]",strin1);
    message_compression(strin1);
    // printf("%sx",strin1);

    if(*strin1 == '\0'){
        printf("NothingToShow");
        return 0;
    }
    printf("%s",strin1);
    return 0;
}

int message_compression(char* txt){
    if(txt == NULL) return -1;
    capitalize(txt);
    // printf("%s", txt);
    remove_non_letters(txt);
    return delete_spacebars(txt);
}

void remove_non_letters(char* text) {
	
	int i = 0;
	while (*text) {
		if ((*text < 'a' || *text > 'z') && (*text < 'A' || *text > 'Z')) {
			*text = ' ';
		}
		text++;
		i++;
	}
	// text = text - i;
}	

void capitalize(char* text){
    for(int i = 0; *(text+i); i++){
        if(*(text+i)>='A' && *(text+i)<='Z') *(text+i)=*(text+i)-'A'+'a'; //all letters to lower
    }

    if(*text >= 'a' && *text <='z') *text = *text-'a'+'A';    //if first char letter, first char upper

    for(int i = 0; *(text+i); i++){
        if(i != 0){
            if((*(text+i-1) == ' ' || ((*(text+i-1) < 'a' || (*(text+i-1) >'z')) && ((*(text+i-1) < 'A' || (*(text+i-1) >'Z')))))){
                if(*(text+i)>='a' && *(text+i)<='z'){
                    *(text+i) = *(text+i)-'a'+'A';
                }
            }
        }
    }
}

int delete_spacebars(char* text){
    int counter = 0;
    for(int i = 0; *(text+i); i++){
        if(*(text+i) == ' '){
            counter++;
            int j = 0;
            for(j = 0; *(text+i+j); j++){
                *(text+i+j) = *(text+i+j+1);
            }
            *(text+i+j-1) = *(text+i+j);
            i--;
        }
    }
    return counter;
}