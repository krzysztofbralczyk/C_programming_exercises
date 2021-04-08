
#include <stdio.h>

int main()
{
    int num,correct;
    printf("Number please:\n");
    correct = scanf("%d",&num);
    
    switch(correct)
    {
        case 0:
        printf("Incorrect input");
        return 1;
    }
    switch(num)
    {
        case 1:
        printf("poniedzialek");
        break;
        
        case 2:
        printf("wtorek");
        break;
        
        case 3:
        printf("sroda");
        break;
        
        case 4:
        printf("czwartek");
        break;
        
        case 5:
        printf("piatek");
        break;
        
        case 6:
        printf("sobota");
        break;
        
        case 7:
        printf("niedziela");
        break;
        
        default:
        printf("Incorrect input");
        return 1;
    }

    return 0;
}