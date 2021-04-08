#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int a,b;
    printf("Daj 2 liczby!\n");
 
    
    switch(scanf("%d %d",&a,&b)){
        case 0:
        case 1:
        printf("Incorrect input");
        return 1;
    }
    
    
    switch(a>b){
        case 0:
        printf("%d\n%d",b,a);
        break;
        
        case 1:
        printf("%d\n%d",a,b);
        break;
    }

    return 0;
}
