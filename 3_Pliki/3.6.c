#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* f2 = fopen("2.txt","w");
    if(f2 == NULL){
        printf("Couldn't create file");
        exit(5);
    }
    fclose(f2);

    FILE* f3 = fopen("3.txt","w");
    if(f3 == NULL){
        printf("Couldn't create file");
        exit(5);
    }
    fclose(f3);

    FILE* f5 = fopen("5.txt","w");
    if(f5 == NULL){
        printf("Couldn't create file");
        exit(5);
    }
    fclose(f5);

    FILE* f0 = fopen("0.txt","w");
    if(f0 == NULL){
        printf("Couldn't create file");
        exit(5);
    }
    fclose(f0);

    printf("Podaj liczby:");
    int number = 0;
    scanf("%d",&number);
    while(number != 0){
        if(number % 2 == 0){
            FILE* f2 = fopen("2.txt","a");
            fprintf(f2,"%d\n",number);
            fclose(f2);
        }
        if(number % 3 == 0){
            FILE* f3 = fopen("3.txt","a");
            fprintf(f3,"%d\n",number);
            fclose(f3);
        }
        if(number % 5 == 0){
            FILE* f5 = fopen("5.txt","a");
            fprintf(f5,"%d\n",number);
            fclose(f5);
        }
        if(number % 2 != 0 && number % 3 != 0 && number % 5 != 0){
            FILE* f0 = fopen("0.txt","a");
            fprintf(f0,"%d\n",number);
            fclose(f0);
        }
        scanf("%d",&number);
    }
    
    printf("Files saved");
    return 0;
}