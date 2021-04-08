#include "array.h"

int array_create(struct array_t *a, int N){
    if(N <= 0 || a == NULL) return 1;
    a->ptr = (int*)malloc(N*sizeof(int));
    if(a->ptr == NULL) return 2;
    a->size = 0;
    a->capacity = N;
    return 0;
}

int array_push_back(struct array_t *a, int value){
    if(a == NULL || a->ptr == NULL || a->size < 0 || a->capacity <= 0 || a->size > a->capacity) return 1;
    if(a->size == a->capacity) return 2;
    *((a->ptr) + a->size) = value;
    a->size++;
    return 0;
}

void array_display(const struct array_t *a){
    if(a == NULL || a->ptr == NULL || a->size > a->capacity) return;
    for(int i = 0; i < a->size; i++){
        printf("%d ",*(a->ptr + i));
    }
}

void array_destroy(struct array_t *a){
    if(a == NULL || a->ptr == NULL) return;
    free(a->ptr);
}

int array_copy(const struct array_t *src, struct array_t *dest){

    if(src == NULL || dest == NULL || src->ptr == NULL || dest == src || src->size < 0 || src->capacity <= 0) return 1;
    dest->size = src->size;
    dest->capacity = src->capacity;

    dest->ptr = (int*)malloc(sizeof(int)*(dest->size));
    if(dest->ptr == NULL) return 2;

    for(int i = 0; i < dest->size; i++){
        *(dest->ptr+i) = *(src->ptr+i);
    }
    return 0;
}

int array_separate(const struct array_t *a, struct array_t *odd, struct array_t *even){
    if(a == NULL || odd == NULL || even == NULL || a->ptr == NULL || even == odd || a == odd || a == even) return -1;
    if(a->capacity <= 0 || a->size > a->capacity ||  a->size < 0) return -1;

    int even_counter = 0, odd_counter = 0;
    for(int i = 0; i < a->size; i++){
        if(*(a->ptr+i) % 2 == 0) even_counter++;
        else odd_counter++;
    }

    if(even_counter == 0 && odd_counter != 0){
        array_copy(a,odd);
        return 1;
    }
    if(odd_counter == 0 && even_counter != 0){
        array_copy(a,even);
        return 2;
    }



    odd->ptr = (int*)malloc(sizeof(int) * odd_counter);
    if(odd->ptr == NULL) return 0;
    odd->size = odd_counter;
    odd->capacity = odd_counter;

    even->ptr = (int*)malloc(sizeof(int) * even_counter);
    if(even->ptr == NULL){ free(odd->ptr); return 0; }
    even->size = even_counter;
    even->capacity = even_counter;

    even_counter = 0;
    odd_counter = 0;
    for(int i = 0; i < a->size; i++){
        if(*(a->ptr+i) % 2 == 0){
            *(even->ptr+even_counter) = *(a->ptr+i);
            even_counter++;
        }
        else{
            *(odd->ptr+odd_counter) = *(a->ptr+i);
            odd_counter++;
        }
    }


    return 3;
}