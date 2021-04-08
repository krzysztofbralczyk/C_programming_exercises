#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "function.h"

int main(){
    printf("%llu %llu %llu",bits_to_number(NULL, 3, 1,1,1), bits_to_number(NULL, 8, 1,0,0,0,0,0,0,1), bits_to_number(NULL, 32, 1,1,0,1,0,0,0,1, 0,0,0,0,1,1,0,1, 0,1,0,0,1,0,1,1, 1,1,1,0,1,1,1,0));
    return 0;
}