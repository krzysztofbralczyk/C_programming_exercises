#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  int table[11][11];
for(int i = 0; i < 11; i++){
  for(int j = 0; j < 11; j++){
    table[i][j] = i * j;
  }
}

for(int i = 0; i < 11; i++){
  for(int j = 0; j < 11; j++){
    printf("%4d",table[i][j]);
  }
  printf("\n");
}

return 0;
}