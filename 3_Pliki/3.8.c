#include <stdio.h>
#include <stdlib.h>

int main() {

    printf("Podaj sciezke do pliku: ");
    char nazwa_zmiennej[31] = { '\0' };
    scanf("%30[^\n]", nazwa_zmiennej);

    int sum = 0, current = 0;
    FILE* p = fopen(nazwa_zmiennej, "r");
    if (p == NULL) {
        printf("Couldn't open file");
        return 4;
    }

    int returned = fscanf(p, "%d", &current);
    while (returned != EOF) {
        if (returned == 0) {
            printf("File corrupted");
            fclose(p);
            return 6;
        }
        sum += current;
        returned = fscanf(p, "%d", &current);
    }

    fclose(p);
    printf("%d", sum);

    return 0;
}