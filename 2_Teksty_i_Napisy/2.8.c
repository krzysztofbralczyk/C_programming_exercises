#include <stdio.h>

char* change_letter_size(char* dest, const char* src);
int my_strlen(const char* str);

int main(){

    printf("Podaj tekst: ");
    char strin[1001];   
    scanf("%1000[^\n]",strin); 
    char strin2[1001];
    change_letter_size(strin2,strin);
    printf(strin2);
    return 0;
}

char* change_letter_size(char* dest, const char* src){
    if(dest == NULL || src == NULL) return NULL;
    int length = my_strlen(src);
    for(int i = 0; i <= length; i++){
        if(*(src+i)>='a' && *(src+i)<='z') *(dest+i) = ((*(src+i))-'a'+'A');
        else if(*(src+i)>='A' && *(src+i)<='Z') *(dest+i) = ((*(src+i))-'A'+'a');
        else *(dest+i) = *(src+i);
    }
    return dest;
}


int my_strlen(const char* str){
    int length = 0;
    while(*(str+length)) length++;
    return length;
}