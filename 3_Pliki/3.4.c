#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Podaj sciezke do pliku zrodlowego: ");
    char in[31] = {'\0'};
    scanf("%30[^\n]",in);
    while(getchar() != '\n');

    FILE* fin = fopen(in,"r");
    if(fin == NULL) {
        printf("Couldn't open file");
        exit(4);
    }


    printf("Podaj sciezke do pliku docelowego: ");
    char out[31] = {'\0'};
    scanf("%30[^\n]",out);

    FILE* fout = fopen(out,"w");
    if(fout == NULL) {
        printf("Couldn't create file");
        fclose(fin);
        exit(5);
    }

    int c;
    fseek(fin,0,SEEK_END);
    long int length = ftell(fin) - 1;
    if(length < 0){
        fclose(fin);
        fclose(fout);
        printf("File copied");
        return 0;
    }
    fseek(fin,length,SEEK_SET);
    
    while(length != 0){
        c = fgetc(fin);
        fputc(c,fout);
        length--;
        fseek(fin,length,SEEK_SET);
    }
    fputc(fgetc(fin),fout);


    fclose(fin);
    fclose(fout);

    printf("File copied");
    return 0;
}