#include <stdio.h>
#include <stdlib.h>
int main()
{
    
    int num;
    
    printf("Liczby 1:\n");       
    int numbers1[100] = {0}, counter1 = 0;
    num = 1;
    while(num && counter1<100){                  
        if(!scanf("%d",&num) && printf("Incorrect input")) return 1;
        if(num) numbers1[counter1] = num;                       
        if(num) counter1++;                                    
    }
    while ((getchar()) != '\n');
    printf("\n");

    printf("Liczby 2:\n"); 
    int numbers2[100] = {0}, counter2 = 0;
    num = 1;
    while(num && counter2<100){                  
        if(!scanf("%d",&num) && printf("Incorrect input")) return 1;
        if(num) numbers2[counter2] = num;                       
        if(num) counter2++;                                  
    }
    
    if(counter2<1 && counter1<1){
        printf("not enough data available");
        return 2;
    }
    while ((getchar()) != '\n');
    printf("\n");
    
 //koniec wprowadzania danych
 //zaczynamy analize
 
 

    int d = 0,raw_doubles[100] = {0};
    for(int i = 0; i<counter2-1; i++){
        for (int j = i+1; j<counter2; j++){
            if(numbers2[i] == numbers2[j]){
                raw_doubles[d] = numbers2[i];
                d++;
                break;
            }
        }
    }
    
    if(d < 1){
        printf("Nothing to show");
        return 0;
        
    }
    
    int flag;
    int d1 = 1, doubles[1000] = {0};
    doubles[0] = raw_doubles[0];
    for(int i = 1; i<d; i++){
        flag = 1;
        for (int j = i-1; j>=0; j--){
            if(raw_doubles[i] == raw_doubles[j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            doubles[d1] = raw_doubles[i];
            d1++;
        }
    }
    
    int uc = 0, uncommons[1000] = {0};
    for(int i = 0; i < d1; i++){
        flag = 1;
        for(int j = 0; j<counter1; j++){
            if(doubles[i] == numbers1[j]){
                flag = 0;
                break;
            }
        }
        if(flag){
            uncommons[uc] = doubles[i];
            uc++;
        }
    }
    if(uc == 0){
        printf("Nothing to show");
        return 0;
    }
    
    for(int i = 0; i < uc; i++){
        printf("%d ",uncommons[i]);
    }













 
    return 0;
}