#include <stdio.h>

int main()
{
    double b,flag = 1,product=1;
    
    printf("Zachęcam:");
    
    if(!scanf("%lf",&b)){
        printf("Incorrect input");
        flag = 0;
    }
    
    while(flag){
        product *= b;
        printf("Wynik:  %.2lf\n",product);
        
        printf("Zachęcam:");
        if(!scanf("%lf",&b)){
            flag = 0;
            printf("Incorrect input");
        }
    }
    
    
    return 0;
}
