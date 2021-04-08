#include "big_numbers.h"

int add_big_number(struct big_numbers_t *bn, const char *big_number){
    if(bn == NULL || big_number == NULL|| bn->big_number == NULL || bn->size < 0 || bn->capacity <= 0 || bn->size > bn->capacity) return 1;
    if(validate(big_number)!=0) return 1;
    if(bn->size == bn->capacity) return 3;

    int big_num_size = 0;
    while(*(big_number+big_num_size))big_num_size++;
    *(bn->big_number+bn->size) = malloc((big_num_size+1) * sizeof(char));
    if(*(bn->big_number + bn->size) == NULL) return 2;
    strcpy(*(bn->big_number+bn->size),big_number);
    (bn->size)++;
    return 0;
}
void display(const struct big_numbers_t *bn){
    if(bn == NULL || bn->big_number == NULL || bn->capacity <= 0 || bn->size <= 0 || bn->size > bn->capacity) return;
    for(int i = 0; i < bn->size; i++){
        printf("%s\n",*(bn->big_number+i));
    }
}
void destroy(struct big_numbers_t *bn){
    if(bn == NULL) return;
    for(int i = 0; i < bn->size; i++){
        free(*((bn->big_number)+i));
    }
    free(bn->big_number);
}
void destroy_big_numbers(struct big_numbers_t **bn){
    if(bn == NULL || *bn == NULL || (*bn)->big_number == NULL || (*bn)->capacity <= 0 || (*bn)->size < 0 || (*bn)->size > (*bn)->capacity) return;
    destroy(*bn);
    free(*bn);
    *bn = NULL;
}
int create(struct big_numbers_t *bn, int capacity){
    if(bn == NULL || capacity <= 0) return 1;
    bn->capacity = capacity;
    bn->size = 0;
    (bn->big_number) = malloc(capacity*sizeof(char*));
    if(bn->big_number == NULL) return 2;
    return 0;
}
int create_big_numbers(struct big_numbers_t **bn, int capacity){
    if(bn == NULL || capacity <= 0) return 1;
    *bn = (struct big_numbers_t*)malloc(sizeof(struct big_numbers_t));
    if(*bn == NULL) return 2;
    if(create(*bn, capacity) == 2){free(*bn); *bn = NULL; return 2;}
    return 0;
}
int validate(const char* number) {
    if (number == NULL) return -1;
    if (strcmp(number, "") == 0) return 2;

    if (ujemna(number)) {

        if (correct_negative(number)) return 0;
        else return 2;

    }
    else {

        if (correct_positive(number)) return 0;
        else return 2;

    }
}
int ujemna(const char* number) {
    if (*number == '-') return 1;
    else return 0;
}
int correct_negative(const char* number) {
    //takes only strings starting with '-'
    if (minus_only(number) || zero_after_minus(number) || after_minus_contains_not_a_number(number)) return 0;
    return 1;
}
int correct_positive(const char* number) {
    if (starts_with_zero_and_longer_than_one(number) || contains_not_a_number(number)) return 0;
    return 1;
}
int starts_with_zero_and_longer_than_one(const char* number) {
    if (*number == '0' && strlen(number) > 1) return 1;
    else return 0;
}
int contains_not_a_number(const char* number) {
    for (int i = 0; *(number + i); i++) {
        if (!isdigit(*(number + i))) return 1;
    }
    return 0;
}
int minus_only(const char* number) {
    if (strlen(number) == 1) return 1;
    return 0;
}
int after_minus_contains_not_a_number(const char* number) {
    for (int i = 1; *(number + i); i++) {
        if (!isdigit(*(number + i))) return 1;
    }
    return 0;
}
int zero_after_minus(const char* number) {
    //takes only strings longer than 1
    if (*(number + 1) == '0') return 1;
    else return 0;
}