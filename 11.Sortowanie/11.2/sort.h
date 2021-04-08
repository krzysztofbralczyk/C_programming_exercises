#include "direction.h"
#if !defined(_SORT_H_)
#define _SORT_H_
int bubble_sort_asc(int tab[], int size);
int bubble_sort_desc(int tab[], int size);
int bubble_sort(int tab[], int size, enum direction dir);
#endif

