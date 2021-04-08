#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    
    
    //deklaracja zmiennych START
    int numbers[1000] = {0},substrings[1000], num, counter = 0,j,longest=0,subAmount=0,s = 0,longestSubCount=0;
    //deklaracja zmiennych KONIEC
    
    
    
    //wprowadzanie liczb START
    printf("Zachecam do podania liczb:\n");             //jeden tekst zachety na poczatku
    
    if(!scanf("%d",&num)){                              // pierwszy scanf jest po za petla by ja zapoczatkowac
        printf("Incorrect input");                      // scanf razem z sprawdzeniem poprawnosci wartosci
        return 1;    
    }
    
    while(num != 0 && counter<1000){                    //warunek zakonczenia petli: zero na wejsciu lub ponad 1000 elementow
        
        numbers[counter] = num;                         // liczby zostaja przypisane do indeksow 0-999
        counter++;                                      // po ukonczeniu petli counter wynosi od 1 do 1000 ==> reprezentuje ilosc elementow, nie index
        
        if(counter < 1000){                             //wprowadzanie kolejnych liczb z sprawdzeniem poprawnosci wartosci
            if(!scanf("%d",&num)){
                printf("Incorrect input");
            return 1;
            } 
        }
    }
    //wprowadzanie liczb KONIEC



    
    
    for(int i = 1; i<counter-1; i++){            //petla od pierwszego do przedostatniego elementu
        if(counter>2 && ((numbers[i-1]>=numbers[i])^(numbers[i]>=numbers[i+1]))){  // tablica ma ponad dwie liczby
            j = i-1;
            
            while((((numbers[i-1]>numbers[i])^(numbers[i]>numbers[i+1]))/*||((numbers[i-1]>=numbers[i])^(numbers[i]>numbers[i+1]))*/) && i < counter-1){
                i++;
            }
            if(i-j+1>longest) longest = i-j+1; // ustalanie najdluzszego podciagu
            subAmount++;
            substrings[s] = j;
            substrings[s+1] = i-j+1;
            s+=2;
        }
        
    }
    
    // wyznaczenie najdluszczego podciagu START
    for(int a = 0;a<subAmount*2;a+=2){
        if(substrings[a+1] == longest){
            longestSubCount++;
        }
    }
    // wyznaczenie najdluszczego podciagu END
    
    printf("%d\n",longest);          // print dlugosc najdluzszego podciagu
    printf("%d\n",longestSubCount);  // print ilosc najdluzszych podciagow
    
    
    //drukowanie indeksow najdluzszych podciagow i wartosci najdluzszych podciagow START
    for(int a = 0;a<subAmount*2;a+=2){
        if(substrings[a+1] == longest){
            
            printf("%d - ",substrings[a]);
            for(int x = substrings[a]; x<(substrings[a]+substrings[a+1]); x++){
                printf("%d ",numbers[x]);
            } 
            
            printf("\n");
        }

    }
    
    //drukowanie indeksow najdluzszych podciagow i wartosci najdluzszych podciagow END
    
    return 0;
}