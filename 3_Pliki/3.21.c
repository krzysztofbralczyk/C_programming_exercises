#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Podaj sciezke do pliku: ");
    char nazwa_zmiennej[31] = { '\0' };
    scanf("%30[^\n]", nazwa_zmiennej);

    FILE* fp = fopen(nazwa_zmiennej,"r");
    if(fp == NULL){
        printf("Couldn't open file");
        return 4;
    }

    fseek(fp,0,SEEK_END);
    int eof_position = ftell(fp);
    fseek(fp,0,SEEK_SET);




    long int index = 0;
    int returned = 0;
    long int origin = 0;

    while(1){

        returned = fscanf(fp,"%ld",&index);

        if(returned == 0 || returned == -1 || index >= eof_position){
            printf("File corrupted");
            fclose(fp);
            return 6;
        }

        origin = ftell(fp);
        fseek(fp,index,SEEK_SET);
        fgetc(fp);
        fseek(fp,origin,SEEK_SET);

        if(fgetc(fp) == '\n'){
            break;
        } 
        
    }

    fseek(fp,0,SEEK_SET);
    while(1){                                     

        fscanf(fp,"%ld",&index);
        origin = ftell(fp);
        fseek(fp,index,SEEK_SET);
        printf("%c",fgetc(fp));
        fseek(fp,origin,SEEK_SET);

        if(fgetc(fp) == '\n'){
            break;
        } 
    }

    fclose(fp);
    return 0;
}