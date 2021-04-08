#include <stdio.h>
#include <stdlib.h>
int file_size_from_path(const char *path);
// int file_size_from_file(FILE *f);

int main(){
    
    printf("Podaj sciezke do pliku: ");
    char nazwa_zmiennej[31] = {'\0'};
    scanf("%30[^\n]",nazwa_zmiennej);

    FILE* f = fopen(nazwa_zmiennej,"r");
    int size1 = file_size_from_file(f);
    if (size1 == -2){
        printf("Couldn't open file");
        exit(4);
    }
    fclose(f);

    int size2 = file_size_from_path(nazwa_zmiennej);
    
    if(size1 == -2 || size2 == -2 || size2 == -1){
        printf("Couldn't open file");
        return 4;
    }

    if(size1 != size2 || size1 == -1 || size2 == -1){
        printf("error");
    }

    if(size1 == size2){
        printf("%d",size1);
    }

    return 0;
}

int file_size_from_path(const char *path){
    if(path == NULL) return -2;
    int counter = 0;
    FILE* f = fopen(path,"r");
    if(f == NULL) return -1;

    int c = fgetc(f);
    if(ferror(f)) exit(-1);
    while(c != EOF){
        counter++;
        c = fgetc(f);
        if(ferror(f)) exit(-1);
    }
    fclose(f);
    return counter;
}

int file_size_from_file(FILE *f){
    if(f == NULL) return -2;

    

    // int counter = 0;                 //take 1 start
    // int c = fgetc(f);
    // if(ferror(f)) return -1;
    // while(c != EOF){
    //     counter++;
    //     c = fgetc(f);
    //     if(ferror(f)) return -1; 
    // }                                //take 1 end
 
    

    
    long int start = ftell(f);    //take 2 start
    fseek(f,0,SEEK_END);             
    if(ferror(f)) return -1;
    long int counter = ftell(f);          
    fseek(f,start,SEEK_SET);      //take 2 end
    
    return counter;
}