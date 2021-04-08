#include <stdio.h>
#include <stdlib.h>

int main()
{


    
    for(int i = 0;i<=100;i++){
        if(i>=10 && i<15) printf("*%d ",i);
        else if(i>=40 && i <=60) printf("*%d ",i);
        else if(i>70&&i<80) printf("*%d ",i);
        else printf("%d ",i);
    }   
    
    return 0;
}