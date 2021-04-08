#include <stdio.h>
#include <stdlib.h>

int main()
{
    double min,max;
    
    printf("zacheta1\n");
    if(scanf("%lf",&min)!= 1){
        printf("Incorrect input");
        return 1;
    }
    printf("zacheta2\n");
    if(scanf("%lf",&max)!= 1){
        printf("Incorrect input");
        return 1;
    }    
    
    if(max<min){
        printf("Incorrect range");
        return 2;
    }
    
    for(double i = min;i<=max;i+=0.25)printf("%.2lf ",i);

    
    return 0;
}