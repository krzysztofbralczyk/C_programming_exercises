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
    int numbers2[3] = {0}, counter2 = 0;
    num = 1;
    while(num && counter2<3){                  
        if(!scanf("%d",&num) && printf("Incorrect input")) return 1;
        if(num) numbers2[counter2] = num;                       
        if(num) counter2++;                                  
    }
    if(counter1 == 0 || counter2==0){
        printf("not enough data available");
        return 2;
    }
    if(counter2!=2){
        printf("Incorrect input");
        return 1;
    }
    while ((getchar()) != '\n');
    printf("\n");
    
 //koniec wprowadzania danych
 //zaczynamy analize
 
 

    int s = 0,subs_idx[100] = {0},subs_counter = 0;
    for(int i = 0; i<counter1-1; i++){
        if(numbers1[i] == numbers2[0]){
            if(numbers1[i+1] == numbers2[1]){
                subs_counter++;
                subs_idx[s] = i;
                s++;
            }
        }
    }
    
    printf("%d\n",subs_counter);
    for(int i = 0; i < s; i++){
        printf("%d\n",subs_idx[i]);
    }
  







 
    return 0;
}