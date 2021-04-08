#include <stdio.h>
#include <stdlib.h>
int create_array_int(int **ptr, int N);
void destroy_array_int(int **ptr);

int main(){

    printf("Jak duza tablica?: ");
    int size;
    if(!scanf("%d",&size)){
        printf("Incorrect input");
        return 1;
    }
    
    int* whatever2 = NULL;
    int** pt = &whatever2;
    int result = create_array_int(pt,size);
    if(result == 2){
        printf("Failed to allocate memory");
        return 8;
    }
    if(result == 1){
        printf("Incorrect input data");
        return 2;
    }

    printf("Podaj liczby: ");
    for(int i = 0; i < size; i++){
        if(!scanf("%d",(*(pt)+i))){
            printf("Incorrect input");
            destroy_array_int(pt);
            return 1;
        }
    }

    for(int i = size-1; i >= 0; i--){
        printf("%d ",(*((*pt)+i)));
    }

    destroy_array_int(pt);

    return 0;
}

int create_array_int(int **ptr, int N){
    if(N <= 0 || ptr == NULL) return 1;
    *ptr = (int*)malloc(N*sizeof(N));
    if(*ptr == NULL) return 2;
    return 0;
}

void destroy_array_int(int **ptr){
    if(ptr == NULL || *ptr == NULL) return;
    free(*ptr);
    *ptr = NULL;
}