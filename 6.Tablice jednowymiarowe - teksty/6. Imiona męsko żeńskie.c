#include <stdio.h>

int main()
{
    printf("Podaj Imie:\n");

    char name[11];

    scanf("%10s",name);
    
    int i = 0;
    while (name[i] != '\0') i++;

    if (i>=1){
        if (name[i-1] == 'a'){
            printf("Imie zenskie");
        } else {
            printf("Imie meskie");
        }
    }
    
    return 0;
}