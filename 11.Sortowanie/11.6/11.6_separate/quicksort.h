#if !defined(_SORT_H_)
#define _SORT_H_
#include "types_utils.h"
int quicksort_asc(int l, int r, int tab[], int tabSize);
int quicksort_desc(int l, int r, int tab[], int tabSize);
int quicksort(int tab[], int size, enum direction dir);
#endif