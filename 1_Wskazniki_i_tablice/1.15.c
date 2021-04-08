#include <stdio.h>
int clamp(int *v, int lo, int hi);
int swap(int* a, int* b);

int main(){
    int limit_1,limit_2,number;
    printf("Liczba: ");
    if(!scanf("%d",&number)){
        printf("Incorrect input");
        return 1;
    }

    printf("Granica 1: ");
    if(!scanf("%d",&limit_1)){
        printf("Incorrect input");
        return 1;
    }

    printf("Granica 2: ");
    if(!scanf("%d",&limit_2)){
        printf("Incorrect input");
        return 1;
    }

    int clamp_result = clamp(&number,limit_1,limit_2);
    if(clamp_result == 1){
        printf("Incorrect input");
        return 1;
    }
    printf("%d",number);
    return 0;
}

int clamp(int *v, int lo, int hi){
    if(v == NULL) return 1;
    
    if(hi < lo) swap(&lo,&hi);
    if(*v > hi) *v = hi;
    if(*v < lo) *v = lo;
    return 0;
}

int swap(int* a, int* b){
    if(a == NULL || b == NULL) return 1;

    int temp = *b;
    *b = *a;
    *a = temp;

    return 0;
}