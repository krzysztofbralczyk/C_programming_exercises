#include <stdio.h>

int main()
{
    int i = 0,j = 0,correct = 0,a = 0,b = 0,tab[10],prime = 0;
    printf("Zachecam do podania dwoch liczb razy piec:\n");
    
    for(i = 0;i<10;i+=2){
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
        if(tab[i]<2){
            printf(" other\n");
        }
        else{
            prime = 1;
            for(j = 2;j<tab[i];j++){
                if(tab[i]%j==0){
                    printf(" composite\n");
                    prime = 0;
                    break;
                }
            }
            if(prime){printf(" prime\n");}
        }
        
    }
    
    return 0;
    
}