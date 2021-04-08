#include <stdio.h>
int main(void)
{
    
    int a;
	printf("Zarzuć czas w sekundach:");
	scanf("%d",&a);
	printf("%02d:%02d:%02d",((a - a%60)/60-((a - a%60)/60)%60)/60,((a - a%60)/60)%60,a%60);

	return 0;
}