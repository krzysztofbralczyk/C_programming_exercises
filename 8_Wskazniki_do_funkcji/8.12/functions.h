#ifndef FUNCTIONS_H
#define FUNCTIONS_H

    #include <stdio.h>
    #include <math.h>
    #include <time.h>
    #include <stdlib.h>
    void print_chicken(void);
    void print_egg(void);
    void print_rabbit(void);
    void (**easter(int size, void(*func1)(void), void(*func2)(void), void(*func3)(void)))(void);

#endif