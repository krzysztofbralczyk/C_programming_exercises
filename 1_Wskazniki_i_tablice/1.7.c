#include <stdio.h>
int sum(const float* tab, unsigned int size, float *result);
int avg(const float* tab, unsigned int size, float *result);
int read_vector_float(float *vec, int size, float stop_value);

int main(){

    printf("Podaj liczby: ");
    float numbers[100];
    int vector_length = read_vector_float(numbers,100,0);
    if(vector_length == 0){
        printf("Not enough data available");
        return 3;
    } else if(vector_length == -2){
        printf("Incorrect input");
        return 1;
    }

    float vector_sum = 12345;
    float vector_avg = 12345;
    sum(numbers,vector_length,&vector_sum);
    avg(numbers,vector_length,&vector_avg);
    printf("Suma: %.2f\nSrednia: %.2f",vector_sum,vector_avg);


    return 0;
}

int sum(const float* tab, unsigned int size, float *result){
    if(!tab || !result || size == 0) return 1;
    float sum = 0.0;

    for(int i = 0; i < (int)size; i++){
        sum += *(tab+i);
    }

    *result = sum;
    return 0;
}

int avg(const float* tab, unsigned int size, float *result){
    if(!tab || !result || size == 0) return 1;
    float sum = 0.0;

    for(int i = 0; i < (int)size; i++){
        sum += *(tab+i);
    }

    *result = sum/size;
    return 0;
}

int read_vector_float(float *vec, int size, float stop_value){
    if(!vec || size <= 0) return -1;

    int ele_counter = 0;
    float number;

    if(!scanf("%f",&number)) return -2;
    while (ele_counter < size && number != stop_value){
        *(vec+ele_counter) = number;
        ele_counter++;
        if(!scanf("%f",&number)) return -2;
    }
    
    return ele_counter;
}