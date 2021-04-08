#include <stdio.h>

int main(void)
{
	float a=2.8,b=5.7;
	printf("%lf %lf\n",a,b);
	printf("%lf\n",a*b);
	printf("%.2lf\n",(double)a/b);
	printf("%lf\n",a+b);
	printf("%lf\n",a-b);
	
	return 0;
}
