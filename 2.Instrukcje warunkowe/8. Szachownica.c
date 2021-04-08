#include <stdio.h>

int main()
{
    printf("Podaj pole:\n");
    int num,correctInput;
    char letter;
    correctInput = scanf("%c%d",&letter,&num);
    if(correctInput==2 && letter-'a'<9 && num <9 && letter-'a'+1>0 && num>0)
    {
        if((num + (letter-'a'+1))%2==0) printf("black");
        else printf("white");
        return 0;
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }
    
    

}