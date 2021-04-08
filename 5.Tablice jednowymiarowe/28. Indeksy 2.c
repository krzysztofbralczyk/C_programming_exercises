#include <stdio.h>

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
    
    
    if(counter1 < 2){
        printf("not enough data available");
        return 2;
    }
    int min = numbers1[0], max = numbers1[0];
    for(int i = 0; i < counter1; i++){
        if(numbers1[i]>max) {
            max = numbers1[i]; 
        }
        if(numbers1[i]<min){ 
            min = numbers1[i];
        }
    }
    int idx_sum = 0,idx_count=0;
    for(int i = 0; i < counter1; i++){
        if (numbers1[i] == min || numbers1[i] == max){
            idx_count++;
            idx_sum += i;
        }
    }
    printf("%d", numbers1[idx_sum/idx_count]);
    
    
    
    
    return 0;
}