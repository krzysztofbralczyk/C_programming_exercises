#include <stdio.h>

int GCD(int a, int b){
    if(a == 0 || b == 0) return (a==0)?(b>0)?b:-b:(a>0)?a:-a;
    if(a%b == 0) return (b<0)?-b:b;
    return GCD(b,a%b);
} 

int main(){

    printf("Liczbe prosze: ");
    int a;
    if(!scanf("%d",&a)){
        printf("Incorrect input");
        return 1;
    }

    printf("Liczbe prosze: ");
    int b;
    if(!scanf("%d",&b)){
        printf("Incorrect input");
        return 1;
    }

    int GCD_result = GCD(a,b);
    // if(GCD_result == 0){
    //     printf("Incorrect input");
    //     return 1;
    // }
    printf("%d",GCD_result);
    return 0;
}