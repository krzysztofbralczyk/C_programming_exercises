#include <math.h>
#include <stdio.h>


int main()
{
    double c,f,k;
    printf("Wprowadz temperature w stopniach celciusza:\n");
    scanf("%lf",&c);


    f = c*9.0/5+32;
    k = c+273.15;
    
    printf("%lf\n",k);
    printf("%lf\n",f);

    

    return 0;
}
