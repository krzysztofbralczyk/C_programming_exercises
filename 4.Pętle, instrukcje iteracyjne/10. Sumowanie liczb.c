#include <stdio.h>
#include <math.h>
int main()
{
  double sum = 0,b;
  
  for(int a = 0; a<10; a++){
    printf("liczbe prosze:\n");
    if(scanf("%lf",&b)==0){
      printf("Incorrect input");
      return 1;
    }
    sum += b;
  }
  printf("%lf",sum);
  return 0;
}