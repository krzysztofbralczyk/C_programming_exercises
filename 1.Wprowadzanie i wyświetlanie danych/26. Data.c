#include <stdio.h>
int main()
{
    int a,b,c;
    printf("Podaj date: ");
    
    
    
    scanf("%d-%d-%d",&a,&b,&c);
    
    printf("Day:%7.02d\nMonth:%5.02d\nYear:%6.04d",a,b,c);
    
    return 0;
}