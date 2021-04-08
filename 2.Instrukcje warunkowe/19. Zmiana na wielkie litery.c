#include <stdio.h>

int main()
{
    char a,b,c,d,e;
    printf("Podaj 5 liter:\n");
    scanf("%c %c %c %c %c",&a,&b,&c,&d,&e);
    
    if(a >= 'a') printf("%c", a-32);
    else printf("%c", a);
    
    if(b >= 'a') printf("%c", b-32);
    else printf("%c", b);
    
    if(c >= 'a') printf("%c", c-32);
    else printf("%c", c);
    
    if(d >= 'a') printf("%c", d-32);
    else printf("%c", d);
    
    if(e >= 'a') printf("%c", e-32);
    else printf("%c", e);
    
    return 0;
}