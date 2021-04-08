#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc < 3){printf("Not enough arguments"); return 9;}

    FILE *fp_r = fopen(*(argv+1),"r");
    if(fp_r == NULL) {printf("Couldn't open file"); return 4;}

    FILE *fp_w = fopen(*(argv+2),"w");
    if(fp_w == NULL) {printf("Couldn't create file"); fclose(fp_r); return 5;}
    char temp = fgetc(fp_r);
    while(!feof(fp_r)){
        fputc(temp,fp_w);
        temp = fgetc(fp_r);
    }

    fclose(fp_w);
    fclose(fp_r);
    printf("File copied");
    return 0;
}