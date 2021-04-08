#include <stdio.h>
#include <math.h>
int main()
{
    double a,b,c;
    printf("Program rozwiazujacy rownanie kwadratowe\n");
    printf("Podaj a: \n");
    scanf("%lf",&a);
    printf("Podaj b: \n");
    scanf("%lf",&b);
    printf("Podaj c: \n");
    scanf("%lf",&c);
    
    if(a==0 && b==0 && c==0){
        printf("nieskonczonosc");
    }
    
    else if(pow(b,2)-4*a*c < 0 || (a==0 && b==0)){
        printf("brak");
    }
    
    else if(a==0){
        printf("jeden %lf",-c/b);
    }
    
    else if(pow(b,2)-4*a*c==0){
        printf("jeden %lf",-b/(2*a));
    }
    
    else {
        printf("dwa %lf %lf",(-b-sqrt(pow(b,2)-4*a*c))/(2*a),(-b+sqrt(pow(b,2)-4*a*c))/(2*a));
    }
    return 0;
}