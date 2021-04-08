#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c,d,e,max,min,sum,avg;
    printf("Program 5 liczb\n");
    scanf("%lf %lf %lf %lf %lf",&a,&b,&c,&d,&e);
    max = a;
    min = a;
    sum = a+b+c+d+e;
    avg = sum/5;
    if(b>max){
        max = b;
    }
    if(c>max){
        max = c;
    }
    if(d>max){
        max = d;
    }
    if(e>max){
        max = e;
    }
    
    if(b<min){
        min = b;
    }
    if(c<min){
        min = c;
    }
    if(d<min){
        min = d;
    }
    if(e<min){
        min = e;
    }
    
    printf("%.2lf\n%.2lf\n%.2lf",min,max,avg);
    return 0;
}