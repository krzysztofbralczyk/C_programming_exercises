#include <stdio.h>
#include <stdlib.h>
int* create_array_int(int N);
int* copy_array_int(const int* ptr, int N);
void display_array_int(const int* ptr, int N);


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
    int* pt = create_array_int(size);
    if(pt == NULL){
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Podaj liczby: ");
    for(int i = 0; i < size; i++){
        if(!scanf("%d",pt+i)){
            printf("Incorrect input");
            free(pt);
            return 1;
        }
    }

    int* copy = copy_array_int(pt,size);
    if(copy == NULL){
        printf("Failed to allocate memory");
        free(pt);
        return 8;
    }
    display_array_int(pt,size);
    printf("\n");
    display_array_int(copy,size);
    
    free(pt);
    free(copy);
    return 0;
}

int* create_array_int(int N){
    if(N <= 0) return NULL;
    return (int*)malloc(N*sizeof(int));
}

int* copy_array_int(const int* ptr, int N){
    if(ptr == NULL || N <= 0) return NULL;
    int* pt = (int*)malloc(N*sizeof(int));
    if(pt == NULL) return NULL;
    for(int i = 0; i < N; i++){
        *(pt+i) = *(ptr+i);
    }
    return pt;
}
void display_array_int(const int* ptr, int N){
    if(ptr==NULL || N <= 0) return;
    for(int i = 0; i < N; i++){
        printf("%d ",*(ptr+i));
    }
}