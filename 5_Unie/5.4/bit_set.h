#ifndef BIT_SET_H
#define BIT_SET_H


union bit_set
{
    unsigned int number;
    short c1[2];
    char c2[sizeof(int)];
    struct
        {
        unsigned char bit1 : 1;
        unsigned char bit2 : 1;
        unsigned char bit3 : 1;
        unsigned char bit4 : 1;
        unsigned char bit5 : 1;
        unsigned char bit6 : 1;
        unsigned char bit7 : 1;
        unsigned char bit8 : 1;
    } c[4];
};

#endif

