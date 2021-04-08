#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int stack_init(struct stack_t **stack){
     if(stack == NULL) return 1;
    *stack = (struct stack_t*)malloc(sizeof(struct stack_t));
    if(*stack == NULL) return 2;
    (*stack)->head = NULL;
    return 0;
}

int stack_push(struct stack_t *stack, int value){
    if(stack == NULL) return 1;
    struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
    if(node == NULL) return 2;
    node->data = value;
    node->next = stack->head;
    stack->head = node;
    return 0;
}

void stack_display(const struct stack_t* stack){
    if(stack == NULL) return;
    struct node_t* temp = stack->head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}
int stack_pop(struct stack_t* stack, int *err_code){
    if(stack == NULL || stack->head == NULL) {if(err_code!=NULL)*err_code = 1; return 777;}
    int to_be_returned = stack->head->data;
    struct node_t* to_be_freed = stack->head;
    stack->head = stack->head->next;
    free(to_be_freed);
    if(err_code != NULL)*err_code = 0;
    return to_be_returned;
}
void stack_destroy(struct stack_t** stack){
    if(stack == NULL) return;
    while((*stack)->head != NULL){
        struct node_t* temp = (*stack)->head->next;
        free((*stack)->head);
        (*stack)->head = temp;
    }
    if(*stack != NULL)free(*stack);
}
int stack_empty(const struct stack_t* stack){
    if(stack == NULL) return 2;
    if(stack->head == NULL) return 1;
    return 0;
}
