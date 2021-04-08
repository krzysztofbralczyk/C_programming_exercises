#include <stdio.h>
#include <math.h>
int main()
{
    float a;
    int precision;
    printf("Wprowadz liczbe:\n");
    scanf("%f",&a);
    printf("Wprowadz precyzje:\n");
    scanf("%d",&precision);
    printf("%.*f",precision,a);

    return 0;
}
