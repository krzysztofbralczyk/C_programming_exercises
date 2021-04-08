#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main()
{
    int a,b,correct;
    char op;
    printf("First number: ");
    if(!scanf("%d",&a)){
        printf("Incorrect input");
        return 1;
    }
    
    printf("Second number: ");
    if(!scanf("%d",&b)){
    printf("Incorrect input");
    return 1;
    }
    
    printf("Operator: ");
    correct = scanf(" %c",&op);
    if(!(correct&&(op=='-'||op=='+'||op=='/'||op=='*'))){
        printf("Incorrect input");
        return 1;
    }
    
    if(b==0 && op=='/'){
        printf("Operation not permitted");
        return 2;
    }
    

    if(op == '+') printf("%d",a+b);
    if(op == '-') printf("%d",a-b);
    if(op == '*') printf("%d",a*b);
    if(op == '/') printf("%.2lf",(double)a/b);


    return 0;
}