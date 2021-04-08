#include <stdio.h>
#include <math.h>
int main()
{
  for(int a = -10;a<=10;a++){
    for(int b = -10;b<=10;b++){
      if((a+b)*(a-b)==pow(a,2) + pow(b,2)) printf("%d %d\n",a,b);
    }
  }
  return 0;
}