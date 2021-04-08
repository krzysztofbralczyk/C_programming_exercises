#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int sum=0;
    srand(time(NULL));
    
    for(int i = 0;i<100;i++){
    sum += rand()%11+10;
    }
    printf("%d",sum);
    return 0;
}