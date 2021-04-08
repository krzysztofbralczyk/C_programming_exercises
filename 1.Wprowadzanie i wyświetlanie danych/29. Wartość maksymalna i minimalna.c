#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    
    int a,b;
	printf("Zarzuć dwie liczby:");
	scanf("%d %d",&a,&b);
	printf("Maximum: %d\nMinimum:  %d",((a+b)+abs(a-b))/2,((a+b)-abs(a-b))/2);

	return 0;
}