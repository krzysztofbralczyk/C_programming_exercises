#include <stdio.h>

int main()
{
    int a = 0,b = 0,correct = 0,rowZero;
    char op = 'a';
    printf("Podaj liczby:\n");
    correct = scanf("%d %d",&a,&b);
    
    switch(correct)
    {
        case 0:
        case 1:
        printf("Incorrect input");
        return 1;
    }
    
    
    printf("Podaj operator:\n");
    scanf(" %c",&op);

    

    switch(op=='+' || op=='-'|| op=='*'|| op=='/')
    {
        case 0:
        printf("Incorrect input");
        return 1;
    }

    switch(op)
    {
        case '+':
        printf("%d",a+b);
        break;
        
        case '-':
        printf("%d",a-b);
        break;
        
        case '*':
        printf("%d",a*b);
        break;
        
        case '/':
        rowZero = b==0;
        switch(rowZero)
        {
            case 0:
            printf("%.2lf",(float)a/b);
            break;
            
            case 1:
            printf("Illegal operation");
            return 2;
        }
        break;
    }

    return 0;
}