#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,sumE=0,sumO=0;
    printf("zacheta\n");
    if(!scanf("%d",&a)){
        printf("Incorrect input");
        return 1;
    }
    
    while(a!=-1){
    
        if(a%2==0) sumE+= a;
        else sumO += a;
        
        
        if(!scanf("%d",&a)){
            printf("Incorrect input");
            return 1;
        }
    }
    printf("%d\n%d",sumE,sumO);
    
    return 0;
}
