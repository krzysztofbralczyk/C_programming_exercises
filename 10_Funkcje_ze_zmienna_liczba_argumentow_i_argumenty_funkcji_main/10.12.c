#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    if(argc < 2){printf("Not enough arguments"); return 9;}
    int sum = 0;

    for(int i = 1; i < argc; i++){

        for(unsigned int j = 0; j < strlen(*(argv+i));j++){
            
            if(!isdigit(*(*(argv+i)+j)) && *(*(argv+i)+j) != '-' ) {printf("Incorrect input"); return 1;}
            if((*(*(argv+i)+j) == '-' && j != 0)) {printf("Incorrect input"); return 1;}
        }

        sum += atoi(*(argv+i));
   
    }
    
    printf("%d",sum);
    return 0;
}