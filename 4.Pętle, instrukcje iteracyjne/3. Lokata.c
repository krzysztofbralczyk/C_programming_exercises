#include <stdio.h>
#include <math.h>
int main()
{
    int okres,i,correct;
    double kwota;
    
    printf("Podaj kwote:\n");
    correct = scanf("%lf",&kwota);
    if(correct != 1 || kwota<0) 
    {
        printf("Incorrect input");
        return 1;
    }
    
    printf("Podaj okres:\n");
    correct = scanf("%d",&okres);
    if(correct != 1 || okres < 0) 
    {
        printf("Incorrect input");
        return 1;
    }
    
    
    for(i=0;i<okres;i++)
    {
        kwota = kwota*1.01;
    }
    printf("%.2lf",kwota);
    return 0;
}