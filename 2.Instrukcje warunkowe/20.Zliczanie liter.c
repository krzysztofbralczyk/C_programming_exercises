#include <stdio.h>
#include <math.h>
#include <ctype.h>
int main()
{
    char a,b,c,d,e;
    int counter=0;
    printf("Podaj 5 znaków: ");
    scanf("%c%c%c%c%c",&a,&b,&c,&d,&e);
    if(a == 'x' || a=='y' || a=='z'||a=='2'||a=='7') counter++;
    if(b == 'x' || b=='y' || b=='z'||b=='2'||b=='7') counter++;
    if(c == 'x' || c=='y' || c=='z'||c=='2'||c=='7') counter++;
    if(d == 'x' || d=='y' || d=='z'||d=='2'||d=='7') counter++;
    if(e == 'x' || e=='y' || e=='z'||e=='2'||e=='7') counter++;
    printf("Szukane znaki wystapily %d razy(y)",counter);
    
    return 0;
}