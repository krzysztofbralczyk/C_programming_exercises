#include <stdio.h>
#include <math.h>
int main()
{
    int correct;
    double r=0;
    printf("Podaj promien: \n");
    correct = scanf("%lf",&r);
    while(!r || r<0 || !correct){
        printf("Incorrect input\n");
        printf("Podaj promien: \n");
        getchar();
        correct = scanf(" %lf",&r);  
        
    }
    
    printf("Obwod kola %lf\n",2*M_PI*r);
    printf("Pole kola: %lf",M_PI*r*r);
    
    return 0;
}
