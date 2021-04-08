#include <stdio.h>

int read_vector_double(double vec[], int size, double stop_value){
    if(size<1) return -1;
    double num; 
    int counter = 0;
    printf("Podaj wektor (double'a):\n");
    do{
        if(!scanf("%lf",&num)){
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

double horner(double a[], double x, int n){
    if(n <= 0) return -1;
    if(n == 1) return a[n-1];
    else return a[n-1] + x*horner(a,x,n-1);
}

int main(){
    printf("Podaj wspolczynniki wielomianu:  ");
    double A[100];
    int counterA = read_vector_double(A,100,0);
    
    if(counterA == -1){
        printf("Incorrect input");
        return 1;
    }
    if(counterA == 0){
        printf("Not enough data available");
        return 3;
    }
    
    printf("Podaj x:  ");
    double x;
    if(!scanf("%lf", &x)){
        printf("Incorrect input");
        return 1;
    }

    double horner_result = horner(A,x,counterA);
    if(horner_result == -1){
        printf("Incorrect input");
        return 1;
    }

    printf("%.2lf",horner_result);
    return 0;
}