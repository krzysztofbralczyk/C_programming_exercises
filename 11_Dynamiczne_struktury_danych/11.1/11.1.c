#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"
// #include "stack.c"


int main(){
    struct stack_t* stack;
    int stack_init_returned = stack_init(&stack, 10);
    if(stack_init_returned == 2){printf("Failed to allocate memory"); return 8;}
    int operation = 999;
    do{
        printf("Co chcesz zrobic?: ");
        int scanf_returned = scanf("%d",&operation);
        if(scanf_returned != 1){printf("Incorrect input"); stack_free(stack); return 1;}
        if(operation < 0 || operation > 3){printf("Incorrect input data\n"); continue;}
        if(operation == 0){
            break;
        } else if(operation == 1) {
            printf("Podaj liczbe: ");
            int num;
            if(!scanf("%d",&num)){printf("Incorrect input\n"); stack_free(stack); return 1;}
            int push_returned = stack_push(stack,num);
            if(push_returned == 2){printf("Failed to allocate memory"); stack_free(stack); return 8;}
        } else if(operation == 2){
            int error_code;
            int pop_returned = stack_pop(stack,&error_code);
            if(error_code == 2) {printf("Stack is empty\n"); continue;}
            printf("%d\n", pop_returned);
        } else if(operation == 3){
            if(stack->head == 0) {printf("Stack is empty\n"); continue;}
            stack_display(stack);
            printf("\n");
        }
    } while(operation != 0);

    stack_free(stack);
    stack = NULL;
    return 0;
}
