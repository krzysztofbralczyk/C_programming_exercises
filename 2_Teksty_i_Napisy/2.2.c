#include <stdio.h>
char * my_strpbrk ( const char *, const char * );

int main(){

    printf("Podaj tekst: ");
    char string[1001];
    scanf("%1000[^\n]",string);
    char* searched_for = "aeiouyAEIOUY";
    char * current_position;
    int counter = 0;
    current_position = my_strpbrk(string,searched_for);

    while(current_position != NULL){
        counter++;
        current_position = my_strpbrk(current_position+1,searched_for);
        
    }
    printf("%d",counter);
    return 0;
}

char * my_strpbrk ( const char *searched_in, const char *searched_for ){
    for(int i = 0; *(searched_in+i) != '\0'; i++){
        for(int j = 0; *(searched_for+j) != '\0'; j++){
            if(*(searched_in+i) == *(searched_for+j)){
                return (char*)(searched_in + i);
            }
        }
    }
    return NULL;
}