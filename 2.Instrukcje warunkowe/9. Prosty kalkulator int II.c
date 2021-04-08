#include <stdio.h>

int main(void)
{
	int a,b,corr1,corr2;

	printf("Podaj pierwsza liczbe:");
	corr1 = scanf("%d",&a);
	if(!corr1)
	{
	    printf("Incorrect input");
	    return 1;
	}
	
	printf("Podaj druga liczbe:");
	corr2 = scanf("%d",&b);
		if(!corr2)
	{
	    printf("Incorrect input");
	    return 1;
	}
	
	printf("%d\n",a+b);
	printf("%d\n",a-b);
	printf("%d\n",a*b);
	if(!b)
	{
	   printf("Operation not permitted");
	}
	else printf("%d",a/b);

	
	return 0;
}

	
	
	
	