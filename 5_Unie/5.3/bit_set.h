#ifndef BIT_SET_H
#define BIT_SET_H

// union word_set{
//     int number;
//     short c[2];
// };

union bit_set
{
    char number;
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
    } c;
};

#endif

