#include <stdio.h>

int main()
{
    double a,max=0,min=0,sum=0,initialized = 0;
    printf("100 liczb,raus!");
    for(int i = 0;i<100;i++){
        
        if(!scanf("%lf",&a)){
            printf("Incorrect input");
            return 1;
        }
        
        if(!initialized){
            max = a;
            min = a;
            initialized = 1;
        }
        
        if(min>a) min = a;
        if(max<a) max = a;
        sum += a;
        
    }
    
    printf("%.2lf\n%.2lf\n%.2lf",min,max,(double)sum/100);

    return 0;
}
