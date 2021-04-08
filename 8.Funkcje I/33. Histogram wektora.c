#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"



int histogram_vector(const int vect[], int size, int out[], int size_out, int min_value, int max_value){
    if (size <= 0 || size_out <= 0|| max_value-min_value+1 > size_out) return -1;
    for(int i = 0; i < size_out; i++){
        out[i] = 0;                     //przygotowanie tablicy wyjsciowej  przez zerowanie
    }

    for(int i = 0; i < size; i++){
        if(vect[i] > max_value || vect[i] < min_value) return -1;
        out[vect[i]-min_value]++;
    }
    return max_value-min_value+1;
}

int max_vector(const int vect[], int size){
    if( size <= 0) return -1;
    int max,flag = 1;
    for(int i = 0; i < size; i++){
        if(flag){
            max = vect[i];
            flag = 0;
        }
        if(vect[i] > max) max = vect[i];
    }
    return max;
}

int min_vector(const int vect[], int size){
    if( size <= 0) return -1;
    int min,flag = 1;
    for(int i = 0; i < size; i++){
        if(flag){
            min = vect[i];
            flag = 0;
        }
        if(vect[i] < min) min = vect[i];
    }
    return min;
}

int read_vector(int vec[], int size, int stop_value){
    if(size<1) return -1;
    int num, counter = 0;
    printf("Podaj wektor:\n");
    do{
        if(!scanf("%d",&num)){
        return -1;
        }
        if(num != stop_value){
            vec[counter] = num;
            counter++;
        }
    }while(num != stop_value && counter < size);
    while(getchar()!='\n');
    return counter;
}

void display_vector(const int vec[], int size){
    if(size<1) return;
    for(int i = 0; i < size; i++){
        printf("%d ",vec[i]);
    }
}
int main(){

    int A[100] = {0};
    int counterA = read_vector(A,100,-1);
    if(counterA == -1){
        printf("Incorrect input");
        return 1;
    }
    if(counterA < 1){
        printf("not enough data available");
        return 2;
    }

    int B[21] = {0};
    int counterB = histogram_vector(A,counterA,B,21,min_vector(A,counterA),max_vector(A,counterA));
    if(counterB == -1){
        printf("Incorrect input data");
        return 2;
    }
    int min = min_vector(A,counterA);
    int max = max_vector(A,counterA);

    for(int i = 0; i < min;i++) printf("0 ");
    display_vector(B,counterB);
    for(int i = max; i < 20;i++) printf("0 ");

    return 0;
}
