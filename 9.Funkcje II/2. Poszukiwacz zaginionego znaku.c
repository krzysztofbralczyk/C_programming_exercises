#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[]){
    int i = 0;
    while(tab[i] != '\0') i++;
    return i;
}

int find_char(const char tab[], char c){
    int i = 0;
    while(tab[i] != '\0'){
        if(tab[i] == c){
            return i;
        }
        i++;
    }
    return -1;
}
int rfind_char(const char tab[], char c){
    int i = my_strlen(tab);
    while(i >= 0){
        if(tab[i] == c){
            return i;
        }
        i--;
    }
    return -1;
}

int main(){
    printf("Ciag znakow prosze:  ");
    char A[1001] = {0};
    scanf("%1000[^\n]",A);
    while(getchar()!='\n');
    printf("Char do znalezienia prosze:  ");
    char to_be_found;
    scanf("%c",&to_be_found);

    printf("%d\n%d",find_char(A,to_be_found),rfind_char(A,to_be_found));
    return 0;
}


