#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
  srand(time(NULL));
  printf("%d ",rand()%11+30);
  
  return 0;
}