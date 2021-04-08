#include <stdio.h>
#include <string.h>

int main()
{
    char tekst[] = {'T','o',' ','j','e','s','t',' ','t','e','k','s','t','\x0'};
    
    for(int i = 0; (unsigned)i < (unsigned)strlen(tekst); i++){
        putc(tekst[i],stdout);
        printf(" %d %c\n",tekst[i],tekst[i]);
    }

    
    
    return 0;
}
