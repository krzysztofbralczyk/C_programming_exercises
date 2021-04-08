#include <stdio.h>

int main()
{
    double a,b = 1;
    printf("Podaj kolejna liczbe: ");
    if(!scanf("%lf",&a)){
        printf("Incorrect input");
        return 1;
    }
    if(a==0) return 0;
    while(b != 0){
        printf("Podaj kolejna liczbe: ");
        if(!scanf("%lf",&b)){
            printf("Incorrect input");
            return 1;
        }
        if(b!=0) printf("%lf\n",b-a);
        a = b;
    }
    return 0;
}
