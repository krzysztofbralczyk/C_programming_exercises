#include <stdio.h>
int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg);
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg);


int main(){
    int numbers[5][5] = {{0}};
    printf("Liczby prosze: ");
    
    for(int counter = 0, number = 0; counter < 25; counter++){
        
        if(!scanf("%d",&number)){
            printf("Incorrect input");
            return 1;
        }

        *(*(numbers+(counter/5))+(counter%5)) = number;
    }

    int max = 0,min = 0;
    float avg = 0.0;
    
    for(int i = 0; i < 5; i++){

        int res = column_statistics(*numbers, 5, 5, i, &max, &min, &avg);
        if(res == 1){ printf("Incorrect input"); return 1; }
        printf("%d %d %.2f\n",min,max,avg);
    }

  

    for(int i = 0; i < 5; i++){

        int res = row_statistics(*numbers, 5, 5, i, &max, &min, &avg);
        if(res == 1){ printf("Incorrect input"); return 1; }
        printf("%d %d %.2f\n",min,max,avg);
    }

   

    return 0;
}

int column_statistics(const int *ptr, int width, int height, int column_id, int* max, int* min, float *avg){
    if(ptr == NULL || width < 1 || height < 1 || column_id < 0 || max == NULL || min == NULL || avg == NULL || column_id >= width) return 1;
    *min = *(ptr+column_id);
    *max = *(ptr+column_id);
    
    int sum = 0;
    for(int i = column_id; i < width*height; i+=width){
        sum += *(ptr+i);
        if(*(ptr+i) < *min) *min = *(ptr+i);
        if(*(ptr+i) > *max) *max = *(ptr+i);
    }
    *avg = (float)sum/height;

    return 0;
}
int row_statistics(const int *ptr, int width, int height, int row_id, int* max, int* min, float *avg){
    if(ptr == NULL || width < 1 || height < 1 || row_id < 0 || max == NULL || min == NULL || avg == NULL || row_id >= height) return 1;
    *min = *(ptr+(row_id * width));
    *max = *(ptr+(row_id * width));
    
    int sum = 0;
    for(int i = 0; i < width; i++ ){
        sum += *(ptr + row_id * width + i);
        if(*(ptr + row_id * width + i) < *min) *min = *(ptr + row_id * width + i);
        if(*(ptr + row_id * width + i) > *max) *max = *(ptr + row_id * width + i);
    }
    *avg = (float)sum/width;

    return 0;
}