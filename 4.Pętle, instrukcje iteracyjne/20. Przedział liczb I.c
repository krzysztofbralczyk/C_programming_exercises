#include <stdio.h>
#include <stdlib.h>

int main()
{
    int min,max;
    
    printf("zacheta1\n");
    if(scanf("%d",&min)!= 1){
        printf("Incorrect input");
        return 1;
    }
    printf("zacheta2\n");
    if(scanf("%d",&max)!= 1){
        printf("Incorrect input");
        return 1;
    }    
    
    if(max<min){
        printf("Incorrect range");
        return 2;
    }
    
    for(int i = min;i<=max;i++)printf("%d ",i);

    
    return 0;
}
