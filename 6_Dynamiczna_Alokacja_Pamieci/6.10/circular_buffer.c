#include "circular_buffer.h"

int circular_buffer_create(struct circular_buffer_t *a, int N){
    if(a == NULL || N <= 0) return 1;
    a->ptr = (int*)malloc(N*sizeof(int));
    if(a->ptr == NULL) return 2;
    a->begin = 0;
    a->end = 0;
    a->capacity = N;
    a->full = 0;
    return 0;
}

int circular_buffer_create_struct(struct circular_buffer_t **cb, int N){
    if(cb == NULL || N <= 0) return 1;
    *cb = (struct circular_buffer_t*)malloc(sizeof(struct circular_buffer_t));
    if(*cb == NULL) return 2;
    int create_result = circular_buffer_create(*cb,N);
    if(create_result == 2){ free(*cb); return 2;}
    return 0;
}

void circular_buffer_destroy(struct circular_buffer_t *a){
    if(a == NULL || a->ptr == NULL) return;
    free(a->ptr);
}
void circular_buffer_destroy_struct(struct circular_buffer_t **a){
    if(a == NULL) return;
    circular_buffer_destroy(*a);
    free(*a);
}

int circular_buffer_push_back(struct circular_buffer_t *cb, int value){
    if(cb == NULL || cb->ptr == NULL || cb->begin < 0 || cb->capacity <= 0 || cb->end < 0) return 1;
    if((cb->full != 1 && cb->full != 0) || cb->begin > (cb->capacity - 1) || cb->end > (cb->capacity -1)) return 1;
    if(cb->full == 1 && cb->end != cb->begin) return 1;

    if(cb->full == 1) cb->begin++; //if full, there will be overwrite, first num is lost by moving begin pointer forvard
    if(cb->begin > cb->capacity-1)cb->begin = 0; // if we move begin pointer over capacity, we go in circle

    *((cb->ptr) + (cb->end)) = value; // push value into index pointed by end
    cb->end++;                        // increment end by 1
    if(cb->end > cb->capacity-1) cb->end = 0; // if index is bigger than capacity, return to start(make circle)
    if(cb->end == cb->begin) cb->full = 1;
    return 0;
}
int circular_buffer_pop_front(struct circular_buffer_t *a, int *err_code){
    if(a == NULL || a->ptr == NULL || a->begin < 0 || a->capacity <= 0 || a->end < 0) {
        if(err_code != NULL) *err_code = 1; 
        return 9999;
        }
    if((a->full != 1 && a->full != 0) || a->begin > (a->capacity - 1) || a->end > (a->capacity -1)){
        if(err_code != NULL) *err_code = 1;
        return 9999;
    }
    if(a->full == 1 && a->end != a->begin){
        if(err_code != NULL) *err_code = 1;
        return 9999;
    }
    if((a->begin == a->end) && a->full == 0){if(err_code != NULL) *err_code = 2; return 9999;} //jesli bufor pusty

    int to_be_returned = *((a->ptr) + (a->begin));
    if(a->full == 1) a->full = 0; //jesli pelny, napewno przestaje byc pelny
    (a->begin)++;
    if(a->begin > a->capacity-1) a->begin = 0;
    if(err_code != NULL) *err_code = 0;
    return to_be_returned;

}
int circular_buffer_pop_back(struct circular_buffer_t *a, int *err_code){
    if(a == NULL || a->ptr == NULL || a->begin < 0 || a->capacity <= 0 || a->end < 0) {if(err_code != NULL) *err_code = 1; return 9999;}
    if((a->full != 1 && a->full != 0) || a->begin > (a->capacity - 1) || a->end > (a->capacity -1)) {if(err_code != NULL) *err_code = 1; return 9999;}
    if(a->full == 1 && a->end != a->begin) {if(err_code != NULL) *err_code = 1; return 9999;}
    if((a->begin == a->end) && a->full == 0) {if(err_code != NULL) *err_code = 2; return 9999;} //jesli bufor pusty

    if(a->full == 1) a->full = 0;
    (a->end)--;
    if(a->end < 0) a->end = (a->capacity)-1;
    int to_be_returned = *((a->ptr) + (a->end));
    if(err_code != NULL) *err_code = 0;
    return to_be_returned;
}

int circular_buffer_empty(const struct circular_buffer_t *a){
    if(a == NULL || a->ptr == NULL || a->begin < 0 || a->capacity <= 0 || a->end < 0) return -1;
    if((a->full != 1 && a->full != 0) || a->begin > (a->capacity - 1) || a->end > (a->capacity -1)) return -1;
    if((a->begin == a->end) && a->full == 0) return 1; //jesli bufor pusty
    return 0;
}
int circular_buffer_full(const struct circular_buffer_t *a){
    if(a == NULL || a->ptr == NULL || a->begin < 0 || a->capacity <= 0 || a->end < 0) return -1;
    if((a->full != 1 && a->full != 0) || a->begin > (a->capacity - 1) || a->end > (a->capacity -1)) return -1;
    if((a->begin == a->end) && a->full == 1) return 1; //jesli bufor pełny
    return 0;
}

void circular_buffer_display(const struct circular_buffer_t *a){
    if(a == NULL || a->ptr == NULL || a->begin < 0 || a->capacity <= 0 || a->end < 0) return;
    if((a->full != 1 && a->full != 0) || a->begin > (a->capacity - 1) || a->end > (a->capacity -1)) return;
    if(a->full == 1 && a->end != a->begin) return;
    if(circular_buffer_empty(a)) return;
    if(a->full == 1){
        int j = 0;
        for(int i = a->begin; j < a->capacity ; i++, j++){
            printf("%d ",*(a->ptr + ( i % (a->capacity) ) ) );
        }
    } else {
        if(a->end > a->begin){
            for(int i = a->begin; i < a->end; i++){
            printf("%d ",*(a->ptr + i));
            }
        } else {
            int j = 0;
            for(int i = a->begin; j < a->capacity - a->begin + a->end; i++,j++){
                printf("%d ",*(a->ptr + ( i % (a->capacity) ) ) );
            }
        }
        
    }
    
    printf("\n");
}