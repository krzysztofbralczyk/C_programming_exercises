#include <stdio.h>

int main()
{
    int i = 0,correct = 0,a = 0,b = 0,tab[10],sum = 0,min,max;
    printf("Zachecam do podania dwoch liczb razy piec:\n");
    
    for(i = 0;i<10;i+=2){
        correct = scanf("%d %d",&a,&b);

        if (correct!=2){
            printf("Input data type error");
            return 1;
        }

        sum +=a;
        sum +=b;
        
        tab[i] = a;
        tab[i+1] = b;
    }
    
    
    min = tab[0];
    max = tab[0];
    for (i = 0;i<10;i++){
        if (tab[i] < min) min = tab[i];
        if (tab[i] > max) max = tab[i];
    }
    printf("%.4lf\n%d\n%d\n",(double)sum/10,max,min);
    return 0;
    
}