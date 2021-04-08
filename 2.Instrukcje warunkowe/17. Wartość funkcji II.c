#include <stdio.h>
#include <math.h>
int main()
{
    double x;
    
    printf("Podaj liczbe:\n");
    if(!scanf("%lf",&x)){
        printf("Incorrect input");
        return 1;
    }
    
    if(x>5) printf("%lf",(x/2 - 2)*(2-3.0/4*x));
    else if(x<-5) printf("%lf",(x+5)*(x+5)-10);
    else printf("%lf",2*x*x + 3*x - 1);

    return 0;
}