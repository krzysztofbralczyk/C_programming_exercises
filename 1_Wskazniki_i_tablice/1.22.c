#include <stdio.h>
#include <stdlib.h>
int dd_test(const int *ptr, int width, int height);

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
    int dd_result = dd_test(*numbers,5,5);
    if(dd_result == -1){
        printf("Incorrect input");
        return 1;
    }
    if(dd_result == 1) printf("YES");
    else if(dd_result == 0) printf("NO");

    return 0;
}

int dd_test(const int *ptr, int width, int height){
    if(ptr == NULL || width < 1 || height < 1 || width!=height) return -1;
    
    for(int i = 0; i < width*height; i+=width){
        int sum = 0;
        int diag_ele = 0;
        for(int j = 0; j < width ; j++){
            int row_number = i/width;
            if(i+j == row_number*(width+1)){
                diag_ele = abs(*(ptr+i+j));
            } else {
                sum += abs(*(ptr+i+j));
            }
        }
        if(sum >= diag_ele) return 0;
    }

    return 1;
}