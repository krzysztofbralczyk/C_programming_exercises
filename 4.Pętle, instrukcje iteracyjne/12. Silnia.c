#include <stdio.h>

int main()
{
    unsigned long long int a,sum=1,correct,i;
    printf("Liczba prosze!\n");
    correct = scanf("%llu",&a);
    if(!correct||a >=21){
        printf("Incorrect input");
        return 1;
    }
    if(a == 0){
        printf("%d",1);
        return 0;
    }
    
    for(i = 1; i<=a;i++){
        sum *=i;
    }
    
    printf("%llu",sum);
    return 0;
}
