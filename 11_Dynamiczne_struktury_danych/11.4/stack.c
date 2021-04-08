#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int stack_push(struct stack_t** stack, char* value) {
    if (stack == NULL || value == NULL) return 1;
    struct stack_t* node = (struct stack_t*)malloc(sizeof(struct stack_t));
    if (node == NULL) return 2;
    node->sentence = value;
    node->prev = *stack;
    *stack = node;
    return 0;
}

char* stack_pop(struct stack_t** stack, int* err_code) {
    if (stack == NULL || *stack == NULL) { if (err_code != NULL)*err_code = 1; return NULL; }
 
    char* to_be_returned = (*stack)->sentence;
    struct stack_t* to_be_freed = *stack;
    *stack = (*stack)->prev;
    free(to_be_freed);
    if (err_code != NULL)*err_code = 0;
    return to_be_returned;
}

void stack_destroy(struct stack_t** stack) {
    if (stack == NULL) return;
    while (*stack != NULL) {
        struct stack_t* temp = (*stack)->prev;
        free((*stack)->sentence);
        free(*stack);
        *stack = temp;
    }
}

int stack_save(const struct stack_t* stack, const char* filename) {
    if (stack == NULL || filename == NULL) return 1;

    FILE* fp = fopen(filename, "w");
    if (fp == NULL) return 2;

    struct stack_t* copy = (struct stack_t*)stack;
    while (copy != NULL) {
        fprintf(fp, "%s", copy->sentence);
        copy = copy->prev;
    }

    fclose(fp);
    return 0;
}

int stack_load(struct stack_t** stack, const char* filename) {
    if (stack == NULL || filename == NULL || *stack != NULL) return 1;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) return 2;

    while (!feof(fp)) {
        long int pos = ftell(fp);
        int len_without_dot = 0;
        while (fgetc(fp) != '.' && !feof(fp)) len_without_dot++;
        if (feof(fp)) break;
        int len_with_dot = len_without_dot + 1;
        fseek(fp, pos, SEEK_SET);

        char* string = (char*)malloc((len_with_dot + ONE_FOR_TERMINATOR) * sizeof(char));
        if (string == NULL) { stack_destroy(stack); fclose(fp); return 3; } //XXX
        *string = '\0';
        *(string+1) = '\0';

        fscanf(fp, "%[^.]", string);
        if (feof(fp)) break;
        fgetc(fp);
        strcat(string, ".");

        int push_returned = stack_push(stack, string);
        if (push_returned == 2) { stack_destroy(stack);free(string); fclose(fp); return 3; }
    }

    fclose(fp);
    return 0;
}
