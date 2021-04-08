#include <stdio.h>
int is_equal(int a, int b);
int is_negative(int value);
int main(){

    printf("Podaj dwie liczby: ");
    int a, b;
    if(!scanf("%d",&a)){
        printf("Incorrect input");
        return 1;
    }

    if(!scanf("%d",&b)){
        printf("Incorrect input");
        return 1;
    }

    if(is_equal(a,b)) printf("rowne\n");
    else printf("nierowne\n");
    if(is_negative(a))printf("ujemna ");
    else printf("nieujemna ");
    if(is_negative(b))printf("ujemna");
    else printf("nieujemna");
    return 0;
}

int is_equal(int a, int b){
    if(!(a^b)) return 1;
    else return 0;
}
int is_negative(int value){
    if(value & 2147483648) return 1;
    else return 0;
}