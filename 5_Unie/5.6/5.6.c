#include <stdio.h>
#include "bit_set.h"

int main(){

    printf("Enter values: ");
    union bit_set bmp[41] = {'\0'};
    unsigned int number;
    for(int i = 0; i < 40; i++){
        if(!scanf("%x",&number)){
            printf("Incorrect input");
            return 1;
        }
        (*(bmp+i)).number = (char)number;
    }


    printf("Podaj nazwe pliku: ");
    char filename[51] = {'\0'};
    scanf("%50s",filename);

    

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 5; j++){
            if((*(bmp+j+i*5)).c.bit8 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit7 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit6 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit5 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit4 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit3 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit2 == 1) printf("#");
            else printf(" ");
            if((*(bmp+j+i*5)).c.bit1 == 1) printf("#");
            else printf(" ");
        } 
        printf("\n");
    }

    FILE* fp = fopen(filename,"w");
    if(fp == NULL){
        printf("Couldn't create file");               // FOR LATER
        return 5; 
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 5; j++){
            if((*(bmp+j+i*5)).c.bit8 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit7 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit6 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit5 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit4 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit3 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit2 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
            if((*(bmp+j+i*5)).c.bit1 == 1) fprintf(fp,"#");
            else fprintf(fp," ");
        } 
        fprintf(fp,"\n");
    }
    printf("File saved");
    fclose(fp);

    return 0;
}