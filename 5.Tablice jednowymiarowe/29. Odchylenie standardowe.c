#include <stdio.h>
#include <math.h>
int main()
{
    printf("Liczby 1:\n");       
    int numbers1[100] = {0}, counter1 = 0,sum1 = 0;
    int num = 1;
    while(num && counter1<100){                  
        if(!scanf("%d",&num) && printf("Incorrect input")) return 1;
        if(num) numbers1[counter1] = num;                       
        if(num) counter1++;                    
        if(num) sum1 += num;
    }
    while ((getchar()) != '\n');
    printf("\n");
    
    
    if(counter1 < 1){
        printf("not enough data available");
        return 2;
    }
    
    float avg = (float)sum1 / counter1;
    float deviation = 0;
    for(int i = 0; i < counter1; i++){
        deviation += pow(numbers1[i] - avg, 2);
    }
    deviation = sqrt(deviation/(counter1));
    // printf("%d\n",avg);
    // printf("%d\n",deviation);
    int j = 0;
    for(int i = 0; i < counter1; i++){
        if(numbers1[i]>avg+deviation || numbers1[i]<avg-deviation) {
            printf("%d ",numbers1[i]);
            j++;
        }
    }
    
    if(!j) printf("Nothing to show");
    return 0;
}