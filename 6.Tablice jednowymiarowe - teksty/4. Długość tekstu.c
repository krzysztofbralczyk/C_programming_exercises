#include <stdio.h>
#include <string.h>

int main()
{
    char text[1002];
    printf("Podaj teksta wacium Panie:\n");
    fgets(text,1002,stdin);
    int i = 0;
    while(text[i] != '\0'){
        i++;
    }
    printf("%d", i-1);
    return 0;
}
