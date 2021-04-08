#include <stdio.h>
#include <string.h>
int main(void)
{
    
    int a,b,c;


	printf("Zarzuć trzy liczby:");
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",(a>=b)+(a>=c));


	return 0;
}