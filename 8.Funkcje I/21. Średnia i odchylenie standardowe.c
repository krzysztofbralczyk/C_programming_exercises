#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

float average(const int tab[], int size){
    float sum = 0.0;
    for(int i = 0; i < size; i++){
        sum += tab[i];
    }
    if(size <= 0) return -1;
    else return sum/size;

}
float stdDev(const int tab[], int size){
    float avg = average(tab,size);
    float d_sum = 0.0;
    for(int i = 0; i< size; i++){
        d_sum+=pow(tab[i]-avg,2);
    }
    float std_dev = sqrt(d_sum/size);
    if(size <= 0) return -1;
    return std_dev;
}


int main(){
    int num, counter = 0, A[100] = {0};
    printf("Liczby prosze:\n");
    do{
        if(!scanf("%d",&num)){
        printf("incorrect input");
        return 1;
        }
        if(num != 0){
            A[counter] = num;
            counter++;
        }
    }while(num != 0 && counter < 100);
    
    if(counter < 1){
        printf("not enough data available");
        return 2;
    }

    printf("\n%.2f\n%.2f",average(A,counter),stdDev(A,counter));
    return 0;
}

