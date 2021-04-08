
#include <stdio.h>

int main()
{
    int num1,num2,correctType1,correctType2;
    printf("Zachecam do podania pierwszej liczby calkowitej:\n");
    correctType1 = scanf("%d",&num1);
    if(!correctType1)  
    {
        printf("Incorrect input");
        return 1;
    }
    
    printf("Zachecam do podania drugiej liczby calkowitej:\n");
    correctType2 = scanf("%d",&num2);
        if(!correctType2)  
    {
        printf("Incorrect input");
        return 1;
    }
    

    if(!num1 || !num2)
    {
         printf("Operation not permitted");
         return 1;
    }
    else
    {
        if(num1%num2==0) printf("%d is divisible by %d",num1,num2);
        else printf("%d is not divisible by %d",num1,num2);
        return 0;
    }





}