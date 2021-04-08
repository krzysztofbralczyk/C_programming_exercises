#include <stdio.h>
int main()
{
   int a, b;
   
   for (a = 0; a < 11; a++){
       for(b = 0; b < 11; b++){
           printf("%d * %d = %d\n",a,b,a*b);
       }
   }

    return 0;
}