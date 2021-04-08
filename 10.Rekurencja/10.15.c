#include <stdio.h>

int num_length(unsigned long long a){
    if(a == 0) return 0;
    else return num_length(a/10) + 1;
}

void my_ltoa_rec(unsigned long long a, char tab[], int start_index){
    if(start_index == 0) tab[num_length(a)] = '\0'; //seriously? this ****** worked?!?!?
    if(a == 0){
        if(start_index==0){
            tab[0] = '0';
            return;
        } else {
            return;
        } 
    }
    else{
        tab[num_length(a) -1] = (a % 10 + '0');
        my_ltoa_rec(a/10, tab, start_index + 1);
    } 
}

int main(){

    printf("Liczbe prosze: ");
    unsigned long long num;
    int status = scanf("%llu",&num);
    if(status != 1){
        printf("Incorrect input");
        return 1;
    }

    char A[30] = {'\0'};
    my_ltoa_rec(num,A,0);
    printf("%s",A);
    return 0;
}