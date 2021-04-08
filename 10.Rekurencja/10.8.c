#include <stdio.h>

int even_odd(int s, int n){
    if(n < 0) return -1;
    if(n == 0) return s;
    int a = even_odd(s,n-1);
    if(a % 2 == 1 || a % 2 == -1) return 3 * a +1;
    else return a/2;
}

// int even_odd(int s, int n){
//     if(n < 0) return -1;
//     if(n == 0) return s;
//     else if(even_odd(s,n-1) % 2 == 1) return 3 * even_odd(s,n-1) +1;
//     else return even_odd(s,n-1)/2;
// }


int main(){

    printf("Liczbe1 prosze: ");
    int s;
    if(!scanf("%d",&s)){
        printf("Incorrect input");
        return 1;
    }

    printf("Liczbe2 prosze: ");
    int n;
    if(!scanf("%d",&n)){
        printf("Incorrect input");
        return 1;
    }


    long int even_odd_result = even_odd(s,n);
    if(even_odd_result == -1){
        printf("Incorrect input data");
        return 2;
    }

    printf("%ld",even_odd_result);
    return 0;
} 