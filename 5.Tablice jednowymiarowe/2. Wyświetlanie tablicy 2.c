
#include <stdio.h>

int main()
{
    float tab[16]={10, 11, 4, 5, 6, 12, 16, 1, 2, 3, 13, 14, 15, 7, 8, 9};
    int i;
    for(i=0;i<16;i+=2){
        printf("%lf\n",tab[i]);
    }
    return 0;
}
