#ifndef COMPARATORS_H
#define COMPARATORS_H

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    struct point_t
    {
        double x;
        double y;
    };
    int comp_int(const void* num1, const void* num2);
    int comp_double(const void* num1, const void* num2);
    int comp_point(const void* num1, const void* num2);
    int sort(const void* table, int length, int sizeofElement, int(*comparator)(const void*, const void*));

#endif