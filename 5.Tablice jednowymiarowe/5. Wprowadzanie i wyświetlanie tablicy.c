
#include <stdio.h>

int main()
{
    int i,correct;
    float a,b,tab[10];
    printf("Zachecam do podania dwoch liczb:");
    for (i = 0;i<10;i+=2)
    {
        correct = scanf("%f %f",&a,&b);
        if (correct!=2){
            printf("Input data type error");
            return 1;
        }
        tab[i] = a;
        tab[i+1] = b;
    }
    for (i = 0;i<10;i++){
        printf("%d %f\n",i,tab[i]);
    }
    
    return 0;
    
}
