#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    
    
    //deklaracja zmiennych START
    int numbers[100] = {0}, num, counter = 0;
    //deklaracja zmiennych KONIEC
    
    
    
    //wprowadzanie liczb START
    printf("Zachecam do podania liczb:\n");             //jeden tekst zachety na poczatku
    
    if(!scanf("%d",&num)){                              // pierwszy scanf jest po za petla by ja zapoczatkowac
        printf("Incorrect input");                      // scanf razem z sprawdzeniem poprawnosci wartosci
        return 1;    
    }
    
    while(num != 0 && counter<100){                    //warunek zakonczenia petli: zero na wejsciu lub ponad 1000 elementow
        
        numbers[counter] = num;                         // liczby zostaja przypisane do indeksow 0-999
        counter++;                                      // po ukonczeniu petli counter wynosi od 1 do 1000 ==> reprezentuje ilosc elementow, nie index
        
        if(counter < 100){                             //wprowadzanie kolejnych liczb z sprawdzeniem poprawnosci wartosci
            if(!scanf("%d",&num)){
                printf("Incorrect input");
            return 1;
            } 
        }
    }
    while ((getchar()) != '\n');
    
    int num2,smallCounter=0,bigCounter=0;
    printf("Zachecam do podania liczby: "); 
    if(!scanf("%d",&num2)){                              // pierwszy scanf jest po za petla by ja zapoczatkowac
        printf("Incorrect input");                      // scanf razem z sprawdzeniem poprawnosci wartosci
        return 1;    
    }
    printf("\n");
    //wprowadzanie liczb KONIEC
    
    
    if(counter<1){
        printf("not enough data available");
        return 2;
    }
    
    for(int i = 0; i < counter; i++){
        if (numbers[i] < num2) smallCounter++;
        if (numbers[i] > num2) bigCounter++;
    }
    printf("%d\n",smallCounter);
    printf("%d",bigCounter);
    
 

    
    return 0;
}