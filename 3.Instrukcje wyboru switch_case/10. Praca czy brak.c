
#include <stdio.h>

int main()
{
    int num,correct;
    printf("Number please:\n");
    correct =scanf("%d",&num);
    
    switch(correct)
    {
        case 0:
        printf("Incorrect input");
        return 1;
    }
    switch(num)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        printf("Dzien roboczy");
        break;
        
        case 6:
        case 7:
        printf("Weekend");
        break;
        
        default:
        printf("Incorrect input");
        return 1;
    }

    return 0;
}