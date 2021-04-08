#include <stdlib.h>
#include <stdio.h>


int main()
{
    int num,correct=0;
    
    printf("Number please:\n");
    correct += scanf("%d",&num);
    
    switch(abs(num%2)+correct)
    {
        case 1:
        printf("%d is even",num);
        break;
        
        case 2:
        printf("%d is odd",num);
        break;
        
        case 0:
        printf("incorrect input");
        return 1;
    
    }

    return 0;
}