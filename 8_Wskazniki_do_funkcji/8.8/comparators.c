#include "comparators.h"

int comp_int(const void* num1, const void* num2) {
    if(num1 == NULL || num2 == NULL) return 777;
    if (*((int*)num1) > * ((int*)num2)) return 1;
    else if (*((int*)num2) > * ((int*)num1)) return -1;
    else return 0;
}

int comp_double(const void* num1, const void* num2) {
    if(num1 == NULL || num2 == NULL) return 777;
    if (*((double*)num1) > * ((double*)num2)) return 1;
    else if (*((double*)num2) > * ((double*)num1)) return -1;
    else return 0;
}

int comp_point(const void* num1, const void* num2) {
    if(num1 == NULL || num2 == NULL) return 777;
    if (((struct point_t*)num1)->x > ((struct point_t*)num2)->x) return 1;
    else if (((struct point_t*)num2)->x > ((struct point_t*)num1)->x) return -1;
    else {
        if (((struct point_t*)num1)->y > ((struct point_t*)num2)->y) return 1;
        else if (((struct point_t*)num2)->y > ((struct point_t*)num1)->y) return -1;
        else return 0;
    }
}

int sort(const void* table, int length, int sizeofElement, int(*comparator)(const void*, const void*)) {
    if (table == NULL || length <= 0 || sizeofElement <= 0 || comparator == NULL) return 1;

    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 1; i < length; i++) {
            if (comparator((void*)((char*)table + sizeofElement * (i - 1)), (void*)((char*)table + sizeofElement * i)) > 0) {
                sorted = 0;
                void* temp = malloc(sizeofElement);
                if (temp == NULL) return 777;
                memcpy(temp, (void*)((char*)table + sizeofElement * i), sizeofElement);
                memcpy((void*)((char*)table + sizeofElement * i), (void*)((char*)table + sizeofElement * (i - 1)), sizeofElement);
                memcpy((void*)((char*)table + sizeofElement * (i - 1)), temp, sizeofElement);
                free(temp);
            }
        }
    }
    return 0;
}