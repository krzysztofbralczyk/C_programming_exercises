#include <stdio.h>

int main()
{
    double a = 1;
    for(int i = 0; i < 20; i+=1)printf("%.0lf ",(a*=10)/10);
    return 0;
}
