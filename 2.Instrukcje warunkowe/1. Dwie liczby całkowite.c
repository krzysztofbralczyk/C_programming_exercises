#include <stdio.h>

int main(void)
{
  int a, b;
  printf("Podaj dwie liczby calkowite oddzielone spacja:\n");
  if(scanf("%d %d", &a, &b) == 2) printf("%d", a+b);
  else{
    printf("Incorrect input");
    return 1;
  }
  return 0;
}