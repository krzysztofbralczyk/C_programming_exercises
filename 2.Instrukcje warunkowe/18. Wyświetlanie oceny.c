#include <stdio.h>
#include <math.h>
int main()
{
  int x;
  
  printf("Podaj liczbe:\n");
  if(!scanf("%d",&x) || x>20 || x<0){
    printf("Incorrect input");
    return 1;
  }
  
  if (x<=10){
    printf("2");
    return 0;
  }
  if (x<=13){
    printf("3");
    return 0;
  }
  if (x<=16){
    printf("4");
    return 0;
  }
  if (x<=20){
    printf("5");
    return 0;
  }
}