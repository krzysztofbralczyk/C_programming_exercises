#include <stdio.h>

long long binary_exponentiation(long long a, unsigned int n){
    if(n == 0) return 1;
    if(n % 2 == 0) return binary_exponentiation(a*a,n/2);
    else return a * binary_exponentiation(a*a,(n-1)/2);

}

int main(){

    printf("Podstawe prosze: ");
    int x;
    if(!scanf("%d",&x)){
        printf("Incorrect input");
        return 1;
    }

    printf("wyklandik prosze: ");
    int n;
    if(!scanf("%d",&n)){
        printf("Incorrect input");
        return 1;
    }


    printf("%lld",binary_exponentiation(x,n));
    return 0;
}