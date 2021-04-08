#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    
    printf("Podaj liczbe:\n");
    if(!scanf("%d",&a)){
        printf("Incorrect input");
        return 1;
    }
    if(a>0) printf("dodatnia");
    else if(a<0) printf("ujemna");
    else printf("zerowa");

    return 0;
}