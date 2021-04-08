
#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c;
    double length;
    printf("Wprowadz parametr x\n");
    scanf("%d",&a);
    printf("Wprowadz parametr y\n");
    scanf("%d",&b);
    printf("Wprowadz parametr z\n");
    scanf("%d",&c);
    length = sqrt(a*a+b*b+c*c);
    printf("%.2lf",length);

    return 0;
}
