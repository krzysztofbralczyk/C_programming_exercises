#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3){
    
    if(size <= 0 || size2 <= 0 || size3 <= 0) return -1;
    if(size+size2 > size3) return -2;
    for(int i = 0; i < size; i++){
        dest[i] = first[i];
    }
    for(int i = 0; i < size2; i++){
        dest[i+size] = second[i];
    }
    return size + size2;
}
int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3){
    
    if(size <= 0 || size2 <= 0 || size3 <= 0) return -1;
    if(size+size2 > size3) return -2;
    for(int i = 0; i < size2; i++){
        dest[i] = second[i];
    }
    for(int i = 0; i < size; i++){
        dest[i+size2] = first[i];
    }
    
    return size + size2;
}
int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3){
    
    if(size <= 0 || size2 <= 0 || size3 <= 0) return -1;
    if(size+size2 > size3) return -2;
    int bigger_size,destCounter = 0;
    (size>size2) ? (bigger_size = size) : (bigger_size=size2);
    for(int i = 0; i < bigger_size;i++){
        if(i < size){
            dest[destCounter] = first[i];
            destCounter++;
        }
        if(i<size2){
            dest[destCounter] = second[i];
            destCounter++;
        }
    }
    
    return size + size2;
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
    printf("\n");
}


int main(){

    int A[50] = {0};
    int counterA = read_vector(A,50,0); 
    if(counterA == -1){
        printf("Incorrect input");
        return 1;
    }
    if(counterA <1){
        printf("Not enough data available");
        return 2;
    }

    int B[50] = {0};
    int counterB = read_vector(B,50,0);
    if(counterB == -1){
        printf("Incorrect input");
        return 1;
    }
    if(counterB < 1){
        printf("Not enough data available");
        return 2;
    }

    display_vector(A,counterA);
    display_vector(B,counterB);
    
    if(counterA+counterB>50){
        printf("\nOutput buffer is too small");
        return 0;
    } 
    
    int C[50] = {0};
    int counterC = concat_begin(A,counterA,B,counterB,C,50);
    display_vector(C,counterC);
    int D[50] = {0};
    int counterD = concat_end(A,counterA,B,counterB,D,50);
    display_vector(D,counterD);
    int E[50] = {0};
    int counterE = concat_zip(A,counterA,B,counterB,E,50);
    display_vector(E,counterE);

    return 0;
}

