#include <stdio.h>
#include <math.h>
int main()
{
    printf("Liczby 1:\n");       
    int numbers1[100] = {0}, counter1 = 0;
    int num = 1;
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
    while ((getchar()) != '\n');
    printf("\n");

    if(counter1 < 2 || counter2 < 1){
        printf("not enough data available");
        return 2;
    }

    int counter = 0;
    for(int i = 0; i < counter1-1; i++){
        counter = 0;
        for(int j = 0; j < counter2; j++){
            if(numbers1[i]<numbers1[i+1]){
                if(numbers2[j] > numbers1[i] && numbers2[j] < numbers1[i+1]){
                    counter++;
                }
            }
            if(numbers1[i]>numbers1[i+1]){
                if(numbers2[j] < numbers1[i] && numbers2[j] > numbers1[i+1]){
                    counter++;
                }
            }
        }
        printf("%d ", counter);
    }
    
    return 0;
}