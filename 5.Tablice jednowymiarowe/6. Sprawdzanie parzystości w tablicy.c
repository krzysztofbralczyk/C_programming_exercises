
#include <stdio.h>

int main()
{
    int i,correct,a,b,tab[10];
    printf("Zachecam do podania dwoch liczbx5:");
    for (i = 0;i<10;i+=2){
        correct = scanf("%d %d",&a,&b);
        
        if (correct!=2){
            printf("Input data type error");
            return 1;
        }
        
        tab[i] = a;
        tab[i+1] = b;
    }
    
    for (i = 0;i<10;i++){
        printf("%d ",tab[i]);
        if(tab[i]%2==0) printf("even\n");
        else printf("odd\n");
    }
    
    return 0;
    
}
