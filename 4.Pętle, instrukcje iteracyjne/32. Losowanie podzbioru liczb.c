#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    int counter=0;
    srand(time(NULL));
    
    for(int i = 0;i<100;i++){
    if(abs(rand()%2001-1000)<=100) counter++;
    }
    printf("%d\n",counter);
    return 0;
}