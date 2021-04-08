#include <stdio.h>
#include <string.h>
int main(void)
{
    
    int correct;
	int a,au;
	char c;

	printf("Zarzuć liczbą zespoloną:");
	correct = scanf("%d%ci%d",&a,&c,&au);
	printf("%d%c%di\n%d",a,c,au,correct);

	return 0;
}