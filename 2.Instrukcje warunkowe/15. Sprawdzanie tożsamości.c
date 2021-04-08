#include <stdio.h>
#include <math.h>
int main()
{
    int cor,corr;
    double a,b;
    
    printf("Podaj liczbye:\n");
    cor = scanf("%lf",&a);
    if(!cor){
        printf("Incorrect input");
        return 1;
    }
    
    printf("podaj liczb:\n");
    corr = scanf("%lf",&b);
    if(!corr){
        printf("Incorrect input");
        return 1;
    }

    


    
    
    if((a+b)*(a-b) == pow(a,2)+pow(b,2)){
        printf("tozsamosc jest prawdziwa");
    } else{
        printf("tozsamosc nie jest prawdziwa"); 
    }
    

    return 0;
}