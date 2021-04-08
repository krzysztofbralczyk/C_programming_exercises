#include <stdio.h>

int main(void)
{
	int corr1,corr2;
    double a,b;
	printf("Podaj pierwsza liczbe:");
	corr1 = scanf("%lf",&a);
	if(!corr1)
	{
	    printf("Incorrect input");
	    return 1;
	}
	
	printf("Podaj druga liczbe:");
	corr2 = scanf("%lf",&b);
		if(!corr2)
	{
	    printf("Incorrect input");
	    return 1;
	}
	
	printf("%lf\n",a+b);
	printf("%lf\n",a-b);
	printf("%lf\n",a*b);
	if(!b)
	{
	   printf("Operation not permitted");
	}
	else printf("%lf",a/b);

	
	return 0;
}

	
	