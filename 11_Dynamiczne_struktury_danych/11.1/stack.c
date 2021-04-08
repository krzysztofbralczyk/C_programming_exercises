#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int stack_init(struct stack_t **stack, int N){
    if(stack == NULL || N <= 0) return 1;
    *stack = (struct stack_t*)malloc(sizeof(struct stack_t));
    if(*stack == NULL) return 2;
    (*stack)->data = (int*)malloc(N*sizeof(int));
    if((*stack)->data == NULL){
        free(*stack);
        *stack = NULL;
        return 2;
    }
    (*stack)->capacity = N;
    (*stack)->head = 0;
    return 0;
}

int stack_push(struct stack_t *stack, int value){
    if(stack == NULL || stack->head > stack->capacity || stack->data == NULL || stack->head < 0 || stack->capacity == 0) return 1;

    if((stack->head) == (stack->capacity)){
        int* temp;
        temp = (int*)realloc(stack->data,2*(stack->capacity) * sizeof(int));
        if(temp != NULL) {stack->data = temp; (stack->capacity)*=2;}
        else return 2;
    }

    *((stack->data) + (stack->head)) = value;
    (stack->head)++;
    return 0;
}

int stack_pop(struct stack_t *stack, int *err_code){
    if(stack == NULL || stack->head > stack->capacity || stack->data == NULL || stack->head < 0 || stack->capacity == 0) {if(err_code != NULL)*err_code = 1; return 777;}
    if(stack->head == 0){if(err_code != NULL) *err_code = 2; return 777;}
    int to_be_returned = *(stack->data + stack->head - 1);
    (stack->head)--;
    if(err_code!=NULL)*err_code = 0;
    return to_be_returned;
}

void stack_display(const struct stack_t *stack){
    if(stack == NULL || stack->data == NULL || stack->head > stack->capacity || stack->head < 0 || stack->capacity == 0) return;
    for(int i = stack->head; i > 0; i--){
        printf("%d ", *(stack->data + i - 1));
    }
}

void stack_free(struct stack_t *stack){
    if(stack == NULL || stack->data == NULL || stack->head > stack->capacity || stack->head < 0 || stack->capacity == 0) return;
    free(stack->data);
    stack->data = NULL;
    free(stack);
}
