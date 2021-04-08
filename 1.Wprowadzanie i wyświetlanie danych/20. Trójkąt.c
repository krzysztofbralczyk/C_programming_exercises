#include <math.h>
#include <stdio.h>


int main()
{
    double a,b,c,alfa,beta,pi = 3.14159265359;
    printf("Wprowadz a:\n");
    scanf("%lf",&a);
    
    printf("Wprowadz b:\n");
    scanf("%lf",&b);

    c = sqrt(a*a+b*b);
    alfa = atan2(a,b);
    beta = atan2(b,a);
    printf("%.2lf\n",c);
    printf("%.2lf\n",alfa*180/pi);
    printf("%.2lf\n",beta*180/pi);

    

    return 0;
}