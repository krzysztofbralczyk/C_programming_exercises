#include <stdio.h>
#include <stdlib.h>
float* create_array(int N){
    if(N==0) return NULL;
    return (float*)malloc(N*sizeof(float));
}


int main(){
    printf("Jak duza tablica?: ");
    int size;
    if(!scanf("%d",&size)){
        printf("Incorrect input");
        return 1;
    }
    if(size < 1){
        printf("Incorrect input data");
        return 2;
    }
    float* pt = create_array(size);
    if(pt == NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj liczby: ");
    for(int i = 0; i < size; i++){
        if(!scanf("%f",pt+i)){
            printf("Incorrect input");
            free(pt);
            return 1;
        }
    }

     for(int i = size-1; i >= 0; i--){
        printf("%f ",*(pt+i));
    }
    free(pt);
    return 0;
}

