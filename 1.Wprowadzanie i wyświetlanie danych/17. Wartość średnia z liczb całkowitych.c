
#include <stdio.h>


int main()
{
    int a,b,c,d,e,f,g,h,i,j;
    double average;
    printf("Wprowadz 10 liczb oddzielonych spacjami\n");
    scanf("%d %d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);

    average = (a+b+c+d+e+f+g+h+i+j)/10.0;
    printf("%.4lf",average);

    return 0;
}
