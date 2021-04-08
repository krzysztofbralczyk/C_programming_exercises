#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

    #include <stdio.h>
    int read_vector_float(float *vec, int size, float stop_value);
    void display_vector(const int* tab, int size);
    int create_histogram(const float *vec, int size, int *out, int out_size);
    
#endif