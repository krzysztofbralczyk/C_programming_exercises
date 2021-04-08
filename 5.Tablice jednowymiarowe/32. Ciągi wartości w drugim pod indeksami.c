#include <stdio.h>
#include <math.h>
int main()
{
    printf("Liczby 1:\n");       
    int numbers1[100] = {0}, counter1 = 0;
    int num = 1;
    while(num!=-1 && counter1<100){                  
        if(!scanf("%d",&num) && printf("Incorrect input")) return 1;
        if(num!=-1) numbers1[counter1] = num;                       
        if(num!=-1) counter1++;                    
    }
    while ((getchar()) != '\n');
    printf("\n");
    
    printf("Liczby 2:\n");       
    int numbers2[100] = {0}, counter2 = 0;
    num = 1;
    while(num!=-1 && counter2<100){                  
        if(!scanf("%d",&num) && printf("Incorrect input")) return 1;
        if(num!=-1) numbers2[counter2] = num;                       
        if(num!=-1) counter2++;                    
    }
    while ((getchar()) != '\n');
    printf("\n");

    if(counter1 < 1 || counter2 < 1){
        printf("not enough data available");
        return 2;
    }


    for(int i = 0; i < counter1; i++){
        if(numbers1[i] > counter2-1){
            printf("%d ",numbers2[counter2-1]);
        }
        else if(numbers1[i] < 0){
            printf("%d ",numbers2[0]);
        }
        else{
            printf("%d ",numbers2[numbers1[i]]);
        }
    }
    
    return 0;
}