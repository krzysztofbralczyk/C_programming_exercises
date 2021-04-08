#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	srand(time(0));
    int guess,fails=0,num = rand()%(101);
    printf("Zacznij zgadywac!Masz 10 szans:\n");
    while(fails<10){
        scanf("%d",&guess);
        if(guess<num){
            printf("za malo\n");
            fails++;
        }
        else if(guess>num){
            printf("za duzo\n");
            fails++;
        }
        else{
            printf("wygrales");
            return 0;
        }
    }
    printf("przegrales");
    return 0;
    
    
}