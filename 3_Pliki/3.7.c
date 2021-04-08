#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Podaj liczbe liczb:");
    int number;
    if(!scanf("%d",&number)){
        printf("Incorrect input");
        return 1;
    }

    if(number < 1 || number > 1000){
        printf("Incorrect input data");
        return 2;
    }


    char path[10] = {'\0'};

    srand(time(NULL));
    FILE* np;
    int closed = 1;

    for (int i = 0; i < number; i++) {
        
        if(i <= 99){                 //create path start
            *path = i/10 + '0';
            *(path+1) = '.';
            *(path+2) = 't';
            *(path+3) = 'x';
            *(path+4) = 't';
            *(path+5) = '\0';
        } else if( i <= 999){
            *path = i/10/10 + '0';
            *(path+1) = (i/10)%10 + '0';
            *(path+2) = '.';
            *(path+3) = 't';
            *(path+4) = 'x';
            *(path+5) = 't';
            *(path+6) = '\0';
        } else {
            *path = '1';
            *(path+1) = '0';
            *(path+2) = '0';
            *(path+3) = '.';
            *(path+4) = 't';
            *(path+5) = 'x';
            *(path+6) = 't';
            *(path+7) = '\0';
        }                          //create path end

        if(i%10 == 0){
            np = fopen(path,"w");
            closed = 0;
            if(np == NULL){
                printf("Couldn't create file");
                return 5;
            }

            printf("%s\n",path);
        }

        fprintf(np,"%d\n",rand()%1001);

        if(i%10 == 9){
            fclose(np);
            closed = 1;
        }
        
    }

    if(!closed){
        fclose(np);
    }
    return 0;
}