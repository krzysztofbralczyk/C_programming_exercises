#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    
    
    //deklaracja zmiennych START
    int numbers[100] = {0}, num, counter = 0,doubles[100];
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
    
    printf("\n");
    //wprowadzanie liczb KONIEC
    
    
    if(counter<1){
        printf("not enough data available");
        return 2;
    }
    int d = 0;
    int doublesCounter = 0;
    for(int i = 0; i<counter-1; i++){
        for (int j = i+1; j<counter; j++){
            if(numbers[i] == numbers[j]){
                doubles[d] = numbers[i];
                d++;
                doublesCounter++;
                break;
            }
        }
    }
    
    if(doublesCounter==0){
        printf("Nothing to show");
        return 0;
    }
    
    
    int flag;
    printf("%d",doubles[0]);
    
    for(int i = 1; i<doublesCounter;i++){
        flag = 1;
        
        for (int j = i-1; j>=0; j--){
            if(doubles[i] == doubles[j]){
                flag = 0;
                break;
            }
        }
        
        if(flag) printf(" %d ",doubles[i]);
    }

    
    return 0;
}