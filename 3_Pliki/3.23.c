#include <stdio.h>
#include <stdlib.h>
int read_file(const char *filename);

int main() {

    printf("Podaj sciezke do pliku: ");
    char nazwa_zmiennej[31] = { '\0' };
    scanf("%30[^\n]", nazwa_zmiennej);
    int counter = read_file(nazwa_zmiennej);
    if(counter == -1 || counter == 0){
        printf("Couldn't open file");
        return 4;
    }
    printf("%d",counter);
    return 0;
}

void chomp(char *s) {
    while(*s && *s != '\n') s++;
    *s = '\0';
}

int read_file(const char *filename){
    if(filename == NULL) return -1;
    FILE* fp = fopen(filename,"r");
    if(fp == NULL){
        // printf("Failed in opening: %s\n",filename);
        return 0;
    } 
    
    char inside_filename[31] = {'\0'}; 

    int returned = 1;

    while(fgets(inside_filename,sizeof(inside_filename),fp) != NULL){
        chomp(inside_filename);
        printf("%s\n",inside_filename);
        int how_many_oppened = read_file(inside_filename);
        
        returned += how_many_oppened;
    }
    fclose(fp);
    return returned;



    

}