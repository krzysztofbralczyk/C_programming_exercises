#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,sum=0;
    
    printf("10 liczb prosze: ");
    for(int i = 0; i < 10; i++){
        
        if(!scanf("%lf",&a)){
            printf("Incorrect input");
            return 1;
        }
        if (a<0) sum += -a;
        else sum += a;
    }
    printf("%.2lf",sum);
    return 0;
}
