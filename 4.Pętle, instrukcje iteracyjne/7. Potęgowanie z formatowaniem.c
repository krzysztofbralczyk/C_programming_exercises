#include <stdio.h>

int main()
{
    double a = 1;
    for(int i = 0; i < 20; i+=1)printf("10 do potegi %2d = %20.0lf\n",i,(a*=10)/10);
    return 0;
}
