#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Podaj sciezke do pliku: ");
    char nazwa_zmiennej[31] = {'\0'};
    scanf("%30[^\n]",nazwa_zmiennej);


    FILE* fp;                               // create pointer to FILE structure
    fp = fopen(nazwa_zmiennej,"r");         // assign to this pointer actual structure representing file, created by fopen, in read mode
    
    if(fp == NULL){                         // if fopen returned NULL, given path/filename doesn't exist 
        printf("Couldn't open file");        
        exit(4);                            // QUESTION - how is exit different from return? does it close file stream?
    }

    int a = fgetc(fp);
    if(a == EOF){
        printf("Nothing to show");
    }  
    while(a != EOF){    //EOF is always at the of of text file, so by checking for it, we check if we reached End Of File
        putchar(a);
        a = fgetc(fp);
    }

    fclose(fp);


    return 0;
}