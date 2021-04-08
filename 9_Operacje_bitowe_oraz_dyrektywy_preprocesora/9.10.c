#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int longest_series(unsigned int x) {
    int counter = 0;
    int biggest_counter = 0;
    for (unsigned long long int i = (unsigned long long int)pow(2, 32); i > 0; i = i / 2) {
        if (i & x) counter++;
        else {
            if (counter > biggest_counter) biggest_counter = counter;
            counter = 0;
        }
    }
    if (counter > biggest_counter) biggest_counter = counter;
    return biggest_counter;
}

int main() {
    printf("podaj liczbe: ");
    int number;
    if (!scanf("%d", &number)) {
        printf("Incorrect input");
        return 1;
    }
    printf("Wynik: %d", longest_series(number));
    return 0;
}