#include <stdio.h>
int swap(int* a, int* b);

int main(){

    printf("Wpisz 2 liczby int oddzielajac spacja: ");
    int a,b;
    if(scanf("%d %d",&a,&b) != 2){ printf("Incorrect input"); return 1; }

    int swap_result = swap(&a,&b);
    if(swap_result == 1){ printf("Incorrect input"); return 1; }
    
    printf("a: %d  b: %d",a,b);


    return 0;
}

int swap(int* a, int* b){
    if(a == NULL || b == NULL) return 1;

    int temp = *b;
    *b = *a;
    *a = temp;

    return 0;
}