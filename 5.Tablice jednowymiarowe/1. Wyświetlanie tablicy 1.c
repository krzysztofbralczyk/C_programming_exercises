#include <stdio.h>
int main()
{
   int a[11] = {0,1,2,3,4,5,6,7,8,9,10};
   printf("%d %d %d %d %d %d %d %d %d %d %d \n",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9],a[10]);
   int i;
   for(i = 0;i<11;i++){

       printf("%d\n",a[i]);
   }
    return 0;
}