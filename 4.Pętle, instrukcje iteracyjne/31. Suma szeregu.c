#include <stdio.h>
#include <math.h>
int main()
{

    double sum=0,current = 0.5;
    int n = 1;
    
    while(current>=0.0001){
        sum += current;
        n++;
        current = (double)1/(n*(n+1));
    }
    
    printf("%d\n",n-1);
    printf("%.4lf",sum);
    return 0;
}