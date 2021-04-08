#include <stdio.h>

int main(){

    int integer;
    double floating;
    char character;

    int *pointer_to_integer;
    double *pointer_to_floating;
    char *pointer_to_character;

    pointer_to_integer = &integer;
    pointer_to_floating = &floating;
    pointer_to_character = &character;

    *pointer_to_integer = 15;
    *pointer_to_floating = 5.6;
    *pointer_to_character = '$';

    printf("%d %lf %c",*pointer_to_integer, *pointer_to_floating, *pointer_to_character);
    return 0;
}