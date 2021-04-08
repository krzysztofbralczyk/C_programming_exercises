
#include <stdio.h>

int main()
{
    printf("podaj liczbe:\n");
    int n,i,correct;
    correct = scanf("%d",&n);
    if(correct == 0){
        printf("Incorrect input");
        return 1;
    }
    if(n<=1){
        printf("NO");
        return 0;
    }
    
    for(i = 2;i<n-1;i++){
        if(n%i == 0){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
