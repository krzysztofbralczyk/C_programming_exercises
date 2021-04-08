
#include <stdio.h>
// #include <time.h>
// #include <string.h>

int main()
{
    int number,correctType;
    printf("Zachecam do podania liczby:\n");
    correctType = scanf("%d",&number);

    if(correctType)
    {
        if(!number) printf("Equal to zero");
        else printf("Not equal to zero");
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }
    return 0;
}