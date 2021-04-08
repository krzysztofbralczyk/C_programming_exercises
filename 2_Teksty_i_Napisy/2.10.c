#include <stdio.h>

char* space_changer(char*);

int main(){

    printf("Podaj tekst: ");
    char strin1[1001];   
    scanf("%1000[^\n]",strin1);

    printf("%s",space_changer(strin1));
    return 0;
}

char* space_changer(char* text){
    if(text == NULL) return NULL;
    for(int i = 0; *(text+i); i++){
        if(*(text+i) == ' ') *(text+i) = '_';
    }
    return text;
}