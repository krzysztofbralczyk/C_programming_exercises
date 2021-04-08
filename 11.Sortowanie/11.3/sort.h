#include <stdio.h>
#include "vector_utils.h"
#include "direction.h"
#if !defined(_SORT_H_)
#define _SORT_H_
int selection_sort_asc(int tab[], int size);
int selection_sort_desc(int tab[], int size);
int selection_sort(int tab[], int size, enum direction dir);
#endif