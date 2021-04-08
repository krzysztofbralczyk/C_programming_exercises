#include <stdio.h>
#include <string.h>
#include <math.h>
int main(void)
{
    double a,au,b,bu;

    printf("Podaj czesc rzeczywista pierwszej liczby zespolonej:\n");
    scanf("%lf",&a);
    printf("Podaj czesc urojona pierwszej liczby zespolonej:\n");
    scanf("%lf",&au);
    printf("Podaj czesc urojona drugiej liczby zespolonej:\n");
    scanf("%lf",&b);
    printf("Podaj czesc urojona drugiej liczby zespolonej:\n");
    scanf("%lf",&bu);

    
    printf("%.3lf %c i%.3lf %.3lf %c i%.3lf\n",a,(au>=0)*'+'+(au<0)*'-',fabs(au),b,(bu>=0)*'+'+(bu<0)*'-',fabs(bu));
    printf("%.3lf %c i%.3lf\n",a+b,(au+bu>=0)*'+'+(au+bu<0)*'-',fabs(au+bu));
    printf("%.3lf %c i%.3lf\n",a-b,(au-bu>=0)*'+'+(au-bu<0)*'-',fabs(au-bu));
    printf("%.3lf %c i%.3lf\n",a*b-au*bu,(a*bu+b*au>=0)*'+'+(a*bu+b*au<0)*'-',fabs(a*bu+b*au));
    printf("%.3lf %c i%.3lf\n",(a*b+au*bu)/(b*b+bu*bu),((au*b-a*bu)/(b*b+bu*bu)>=0)*'+'+((au*b-a*bu)/(b*b+bu*bu)<0)*'-',fabs((au*b-a*bu)/(b*b+bu*bu)));


    // printf("%.3lf ",(a*b+au*bu)/(b*b+bu*bu));
    // sprintf(buffer,"%+.3lf",(au*b-a*bu)/(b*b+bu*bu));
    // printf("%c ",buffer[0]);
    // buffer[0] = 'i';
    // printf("%s\n",buffer);

    return 0;
}