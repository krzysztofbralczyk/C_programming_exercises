#include <stdio.h>
#include <ctype.h>

char* get_word(char* str);

int main(){

    printf("Podaj tekst: ");
    char strin[1001];   
    scanf("%1000[^\n]",strin); 

    char* word = get_word((char*)strin);
    if(word == NULL){
        printf("Nothing\nto\nshow");
    }
    while(word != NULL){
        printf("%s\n",word);
        word = get_word(NULL);
    }
    

    return 0;
}

char* get_word(char* str){
    static char* previous_value = NULL;
    if(str == NULL) str = previous_value;
    if(str == NULL) return NULL;
    if(*str == '\0') return NULL;

    int i = 0;
    if(!islower(*(str+i)) && !isupper(*(str+i))){
        while(!isupper(*(str+i)) && !islower(*(str+i)) && (*(str+i) != '\0')) i++;
    }
    if(*(str+i) == '\0') return NULL;

    int start = i;
    while(isupper(*(str+i)) || islower(*(str+i))) i++;
    if(*(str+i) == '\0') previous_value = str + i;
    else {
        *(str+i) = '\0';
        previous_value = str + i + 1;
    }
    return str+start;
}