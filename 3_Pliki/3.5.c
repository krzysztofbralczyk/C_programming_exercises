#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Podaj sciezke do pliku docelowego: ");
    char out[31] = {'\0'};
    scanf("%30[^\n]",out);
    while(getchar() != '\n');

    FILE* fout = fopen(out,"w");
    if(fout == NULL) {
        printf("Couldn't create file");
        exit(5);
    }

    for(int i = 0; i < 101; i++){
        if(i<10) {
            fputc(i + '0',fout);
            fputc('\n',fout);
        } else if(i<100) {
            fputc(i/10 + '0',fout);
            fputc(i%10 + '0',fout);
            fputc('\n',fout);
        } else {
            fputc('1',fout);
            fputc('0',fout);
            fputc('0',fout);
        }
        
    }


    fclose(fout);

    printf("File saved");
    return 0;
}