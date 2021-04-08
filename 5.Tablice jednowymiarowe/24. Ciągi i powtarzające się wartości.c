#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    
    
    
    int numbers1[100] = {0}, numbers2[100] = {0}, commons[400] = {0}, num, counter1 = 0, counter2 = 0;
    //                                               
    
    
    
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
    
    int c = 0;
    for(int i = 0;i < counter1;i++){
        for(int j = 0;j<counter2;j++){
            if(numbers1[i]==numbers2[j]){
                commons[c] = numbers1[i];
                c++;
            }
        }
    }
    if(c<1){
        printf("Nothing to show");
        return 0;
    }
    
    //usuwanie duplikatow START
  int flag;
    printf("%d",commons[0]);
    for(int i = 1;i<c;i++){
        flag = 1;
        
        for (int j = i-1;j>=0;j--){
            if(commons[i] == commons[j]){
                flag = 0;
                break;
            }
        }
        
        if(flag)printf(" %d ",commons[i]);
    }
    //usuwanie duplikatow END

    
    return 0;
}