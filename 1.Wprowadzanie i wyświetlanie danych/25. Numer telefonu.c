#include <stdio.h>
int main()
{
    int a,b,c,d;
    printf("Podaj numer telefonu: ");
    scanf("%d-%d-%d",&a,&b,&c);
    printf("Podan kierunkowy: ");
    scanf("%d",&d);
    printf("(%02d) %03d-%02d-%02d",d,a,b,c);
    return 0;
}
