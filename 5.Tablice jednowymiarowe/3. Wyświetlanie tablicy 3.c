
#include <stdio.h>

int main()
{
    int tab[11];
    int i;
    for(i=0;i<11;i++){
        tab[i]=i;
    }
    
    for(i=0;i<11;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
    
    return 0;
    
}
