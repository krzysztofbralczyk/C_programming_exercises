#include <stdio.h>

int main()
{
    double a,max=0,min=0,sum=0,initialized = 0,counter = 0;
    printf("Liczby, raus!");
    
    if(!scanf("%lf",&a)){
        printf("Incorrect input");
        return 1;
    }
    while(a!=-1){
        
        if(!initialized){
            max = a;
            min = a;
            initialized = 1;
        }
        
        if(min>a) min = a;
        if(max<a) max = a;
        sum += a;
        counter++;
        
        if(!scanf("%lf",&a)){
            printf("Incorrect input");
            return 1;
        }
    }
    
    printf("%.2lf\n%.2lf\n%.2lf",min,max,(double)sum/counter);

    return 0;
}
