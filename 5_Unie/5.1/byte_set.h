#ifndef BYTE_SET_H
#define BYTE_SET_H

union byte_set{
    int number;
    char c[sizeof(int)];
};

#endif