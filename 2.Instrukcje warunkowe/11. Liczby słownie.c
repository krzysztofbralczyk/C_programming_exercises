#include <stdio.h>

int main(void)
{
    printf("Podaj liczbe z przedzialu 0-10:\n");
    int a;
    scanf("%d",&a);
    if(a<0 || a>10){
        printf("Blad");
        return 0;
    }
    else if(a == 0) printf("zero");
    else if(a == 1) printf("jeden");
    else if(a == 2) printf("dwa");
    else if(a == 3) printf("trzy");
    else if(a == 4) printf("cztery");
    else if(a == 5) printf("piec");
    else if(a == 6) printf("szesc");
    else if(a == 7) printf("siedem");
    else if(a == 8) printf("osiem");
    else if(a == 9) printf("dziewiec");
    else if(a == 10) printf("dziesiec");
    
	return 0;
}

	
	
	