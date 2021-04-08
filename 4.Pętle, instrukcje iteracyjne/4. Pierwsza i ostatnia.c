#include <stdio.h>
#include <math.h>
int main()
{
    
    unsigned long long int number,first;
    int correct;
    
    printf("Zachecam do podania cyfry:\n");
    correct = scanf("%llu",&number);
    
    
    if (correct != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    
    
    first = number;
    while (first >= 10)
    {
        first = first/10;
    }
    
    
    printf("%llu\n",first);
    printf("%llu",number%10);
    return 0;
}