
#include <stdio.h>


int main()
{
    double a,b,c,d,e;
    double average;
    printf("Wprowadz 5 liczb rzeczywistych oddzielonych spacjami\n");
    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);

    average = (a+b+c+d+e)/5;
    printf("%.4lf",average);

    return 0;
}
