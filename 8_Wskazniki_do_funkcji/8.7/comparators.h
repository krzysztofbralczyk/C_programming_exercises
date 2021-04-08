#ifndef COMPARATORS_H
#define COMPARATORS_H
#include <stdlib.h>
#include <stdio.h>
int comp_min(const int*, const int*, int);
int comp_max(const int*, const int*, int);
int comp_sum(const int*, const int*, int);
int sort_rows(int** table, int width, int height, int(*comparator)(const int*,const int*,int));

#endif