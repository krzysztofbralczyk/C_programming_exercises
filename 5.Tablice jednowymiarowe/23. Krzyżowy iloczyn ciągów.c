#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    
    
    //deklaracja zmiennych START
    int numbers1[100] = {0}, numbers2[100] = {0}, num, counter1 = 0, counter2 = 0;
    //deklaracja zmiennych KONIEC
    
    
    
    //wprowadzanie liczb START
    printf("Zachecam do podania liczb1:\n");             //jeden tekst zachety na poczatku
    
    if(!scanf("%d",&num)){                              // pierwszy scanf jest po za petla by ja zapoczatkowac
        printf("Incorrect input");                      // scanf razem z sprawdzeniem poprawnosci wartosci
        return 1;    
    }
    
    while(num != 0 && counter1<100){                    //warunek zakonczenia petli: zero na wejsciu lub ponad 1000 elementow
        
        numbers1[counter1] = num;                         // liczby zostaja przypisane do indeksow 0-999
        counter1++;                                      // po ukonczeniu petli counter wynosi od 1 do 1000 ==> reprezentuje ilosc elementow, nie index
        
        if(counter1 < 100){                             //wprowadzanie kolejnych liczb z sprawdzeniem poprawnosci wartosci
            if(!scanf("%d",&num)){
                printf("Incorrect input");
            return 1;
            } 
        }
    }
    while ((getchar()) != '\n');
    
    printf("\n");
    //wprowadzanie liczb KONIEC
    
    //wprowadzanie liczb START
    printf("Zachecam do podania liczb2:\n");             //jeden tekst zachety na poczatku
    
    if(!scanf("%d",&num)){                              // pierwszy scanf jest po za petla by ja zapoczatkowac
        printf("Incorrect input");                      // scanf razem z sprawdzeniem poprawnosci wartosci
        return 1;    
    }
    
    while(num != 0 && counter2<100){                    //warunek zakonczenia petli: zero na wejsciu lub ponad 1000 elementow
        
        numbers2[counter2] = num;                         // liczby zostaja przypisane do indeksow 0-999
        counter2++;                                      // po ukonczeniu petli counter wynosi od 1 do 1000 ==> reprezentuje ilosc elementow, nie index
        
        if(counter2 < 100){                             //wprowadzanie kolejnych liczb z sprawdzeniem poprawnosci wartosci
            if(!scanf("%d",&num)){
                printf("Incorrect input");
            return 1;
            } 
        }
    }
    while ((getchar()) != '\n');
    
    printf("\n");
    //wprowadzanie liczb KONIEC
    
    
    if(counter1 < 1 || counter2 < 1){
        printf("not enough data available");
        return 2;
    }
    
    int counter;
    if (counter1 < counter2) counter = counter1;
    else counter = counter2;
    
    for(int i = 0; i < counter;i++){
        printf(" %d ",numbers1[i]*numbers2[counter2-1-i]);
    }
    

    
    return 0;
}