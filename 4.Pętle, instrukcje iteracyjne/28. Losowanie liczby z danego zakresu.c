#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{

    srand(time(NULL));
    int i = 99;
    
    while(i<100 || i >200){
        i = rand()%2001-1000;
        printf("%d\n",i);
    }

    

    return 0;
}