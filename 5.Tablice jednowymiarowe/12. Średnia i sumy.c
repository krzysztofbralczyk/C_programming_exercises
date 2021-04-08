#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    double numbers[1002], bigger = 0.0, smaller = 0.0, sum = 0.0, num;
    int counter = 0;
    printf("Zachecam do podania liczb:\n");
    
    if(!scanf("%lf",&num)){
        printf("Incorrect input");
        return 1;    
    }
    
    while(num != 0 && counter<1000){
        
        numbers[counter] = num;
        counter++;
        
        if(!scanf("%lf",&num)){
            printf("Incorrect input");
            return 1;
        } 
    }
    if(counter==0){
        printf("Brak danych");
        return 0;
    }
    
    for(int i = 0; i < counter;i++){
        sum += numbers[i];
    }
    
    for(int i = 0; i < counter;i++){
        if(numbers[i] > sum/counter) bigger+=numbers[i];
        if(numbers[i] < sum/counter) smaller+=numbers[i];
    }
    
    printf("%.2lf\n%.0lf\n%.0lf",sum/(counter),bigger,smaller);
    
    
    return 0;
}