#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comparators.h"
// #include "comparators.c"
int main() {
    int data_type, array_size;
    printf("Select data_type: ");
    if (!scanf("%d", &data_type)) {
        printf("Incorrect input");
        return 1;
    }
    if (data_type < 0 || data_type > 2) {
        printf("Incorrect input data");
        return 2;
    }
    printf("Enter array size: ");
    if (!scanf("%d", &array_size)) {
        printf("Incorrect input");
        return 1;
    }
    if (array_size <= 0) {
        printf("Incorrect input data");
        return 2;
    }
    int sizeOfElement;
    switch (data_type) {
    case 0:
        sizeOfElement = sizeof(int);
        break;
    case 1:
        sizeOfElement = sizeof(double);
        break;
    case 2:
        sizeOfElement = sizeof(struct point_t);
        break;
    default:
        printf("Wtf? how?");
        return 777;
    }
    void* table = malloc(array_size * sizeOfElement);
    if (table == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Enter numbers:");
    for (int i = 0; i < array_size; i++) {
        switch (data_type) {
        case 0:
            if (!scanf("%d", (int*)((char*)table + (i * sizeOfElement)))) {
                printf("Incorrect input");
                free(table);
                return 1;
            }
            break;
        case 1:
            if (!scanf("%lf", (double*)((char*)table + (i * sizeOfElement)))) {
                printf("Incorrect input");
                free(table);
                return 1;
            }
            break;
        case 2:
            if (scanf("%lf %lf", &(((struct point_t*)((char*)table + (i * sizeOfElement)))->x), &(((struct point_t*)((char*)table + (i * sizeOfElement)))->y)) != 2) {
                printf("Incorrect input");
                free(table);
                return 1;
            }
            break;
        }
    }
    switch (data_type) {
    case 0:
        sort(table, array_size, sizeOfElement, comp_int);
        for (int i = 0; i < array_size; i++) {
            printf("%d ", *(int*)((char*)table + i * sizeOfElement));
        }
        break;

    case 1:
        sort(table, array_size, sizeOfElement, comp_double);
        for (int i = 0; i < array_size; i++) {
            printf("%lf ", *(double*)((char*)table + i * sizeOfElement));
        }
        break;

    case 2:
        sort(table, array_size, sizeOfElement, comp_point);
        for (int i = 0; i < array_size; i++) {
            printf("%lf %lf\n", ((struct point_t*)((char*)table + i * sizeOfElement))->x, ((struct point_t*)((char*)table + i * sizeOfElement))->y);
        }
        break;

    default:
        printf("Wtf? how?");
        return 777;
    }
    free(table);
    return 0;
}

