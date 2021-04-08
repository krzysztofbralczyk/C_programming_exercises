
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
        case 0:
        printf("zero");
        break;
        
        case 1:
        printf("jeden");
        break;
        
        case 2:
        printf("dwa");
        break;
        
        case 3:
        printf("trzy");
        break;
        
        case 4:
        printf("cztery");
        break;
        
        case 5:
        printf("piec");
        break;
        
        case 6:
        printf("szesc");
        break;
        
        case 7:
        printf("siedem");
        break;
        
        case 8:
        printf("osiem");
        break;
        
        case 9:
        printf("dziewiec");
        break;
        
        case 10:
        printf("dziesiec");
        break;
        
        default:
        printf("Incorrect input");
        return 1;
    }

    return 0;
}
