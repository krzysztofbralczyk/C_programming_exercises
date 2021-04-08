#ifndef COMPARATORS_H
#define COMPARATORS_H

#include <stdlib.h>
int comp_int(int, int);
int comp_int_abs(int, int);
int comp_int_length(int, int);
int comp_int_digits_sum(int,int);
int sort_int(int* table, int size, int(*function)(int,int));    

#endif