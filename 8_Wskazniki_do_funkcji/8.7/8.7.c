#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
// #include "comparators.c"

int main(){

    int width, heigth, comparator;
    printf("Enter width and heigth: ");
    if(scanf("%d %d", &width, &heigth) != 2){
        printf("Incorrect input");
        return 1;
    }
    if(width <= 0 || heigth <= 0){
        printf("Incorrect input data");
        return 2;
    }
    int ** rows = (int**)malloc(heigth * sizeof(int*));
    if(rows == NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i = 0; i < heigth; i++){
        *(rows+i) = (int*)malloc(width * sizeof(int));
        if(*(rows+i) == NULL){
            for(int j = 0; j < i; j++){free(*(rows+j));}
            free(rows);
            printf("Failed to allocate memory");
            return 8;
        }
    }
    printf("Enter data");
    for(int i = 0; i < heigth; i++){
        for(int j = 0; j < width; j++){
            if(!scanf("%d",(*(rows + i)+j))){
                printf("Incorrect input");
                for(int k = 0; k < heigth; k++) free(*(rows+k));
                free(rows);
                return 1;
            }
        }
    }
    printf("Select comparator: ");
    if(!scanf("%d",&comparator)){
        printf("Incorrect input");
        for(int k = 0; k < heigth; k++) free(*(rows+k));
        free(rows);
        return 1;
    }
    if(comparator < 0 || comparator > 2){
        printf("Incorrect input data");
        for(int k = 0; k < heigth; k++) free(*(rows+k));
        free(rows);
        return 2;
    }
    switch (comparator) {
    case 0:
        sort_rows(rows,width,heigth,comp_min);
        break;
    case 1:
        sort_rows(rows,width,heigth,comp_max);
        break;
    case 2:
        sort_rows(rows,width,heigth,comp_sum);
        break;
    default:
        break;
    }
    for(int i = 0; i < heigth; i++){
        for(int j = 0; j < width; j++){
            printf("%d ",*(*(rows + i)+j));
        }
        printf("\n");
    }
    for(int k = 0; k < heigth; k++) free(*(rows+k));
    free(rows);
    return 0;
}

// 1  -13 361 -95 -452  -1   -7    2  166   59 -273  68  68  43   11 999   52   -7   -5    6  416    3 284 -83   -1 -80 -728  -26    6  -55  1      1  10 -10  935 -75  746   -7    0   -9  9    -27  57   5   89   2   38 -813 -499 -885