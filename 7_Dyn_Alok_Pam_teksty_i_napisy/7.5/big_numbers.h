#ifndef BIG_NUMBERS_H
#define BIG_NUMBERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct big_numbers_t {
  int size;
  int capacity;
  char **big_number;
};
int create(struct big_numbers_t *bn, int capacity);
int create_big_numbers(struct big_numbers_t **bn, int capacity);
void destroy(struct big_numbers_t *bn);
void destroy_big_numbers(struct big_numbers_t **bn);
int add_big_number(struct big_numbers_t *bn, const char *big_number);
void display(const struct big_numbers_t *bn);
int validate(const char* number);
int ujemna(const char* number);
int correct_negative(const char* number);
int correct_positive(const char* number);
int starts_with_zero_and_longer_than_one(const char* number);
int contains_not_a_number(const char* number);
int minus_only(const char* number);
int after_minus_contains_not_a_number(const char* number);
int zero_after_minus(const char* number);
#endif