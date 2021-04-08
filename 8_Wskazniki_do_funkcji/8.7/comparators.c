#include "comparators.h"

int comp_min(const int* numbers1, const int* numbers2, int size){
    if(numbers1 == NULL || numbers2 == NULL || size <= 0) return 2;
    int min1 = *numbers1, min2 = *numbers2;
    for(int i = 0; i < size; i++){
        if(*(numbers1+i) < min1) min1 = *(numbers1+i);
    }
    for(int i = 0; i < size; i++){
        if(*(numbers2+i) < min2) min2 = *(numbers2+i);
    }

    if(min1 > min2) return 1;
    else if(min2 > min1) return -1;
    else return 0;
}

int comp_max(const int* numbers1, const int* numbers2, int size){
    if(numbers1 == NULL || numbers2 == NULL || size <= 0) return 2;
    int max1 = *numbers1, max2 = *numbers2;
    for(int i = 0; i < size; i++){
        if(*(numbers1+i) > max1) max1 = *(numbers1+i);
    }
    for(int i = 0; i < size; i++){
        if(*(numbers2+i) > max2) max2 = *(numbers2+i);
    }

    if(max1 > max2) return 1;
    else if(max2 > max1) return -1;
    else return 0;
}

int comp_sum(const int* numbers1, const int* numbers2, int size){
    if(numbers1 == NULL || numbers2 == NULL || size <= 0) return 2;
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < size; i++){
        sum1 += *(numbers1+i);
    }
    for(int i = 0; i < size; i++){
        sum2 += *(numbers2+i);
    }

    if(sum1 > sum2) return 1;
    else if(sum2 > sum1) return -1;
    else return 0;
}

int sort_rows(int** table, int width, int height, int(*comparator)(const int*,const int*,int)){
    if(table == NULL || width <= 0 || height <= 0 || comparator == NULL) return 1;

    int sorted = 0;
    while(!sorted){
        sorted = 1;
        for(int i = 1; i < height; i++){
            if(comparator(*(table+i-1), *(table+i), width) > 0){
                sorted = 0;
                int* temp = *(table+i);
                *(table+i) = *(table+i-1);
                *(table+i-1) = temp;
            }
        }
    }
    return 0;
}