#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
//INPUT START
  char string1[1001];
  printf("Zarzuc stringa: ");
  scanf("%1000[^\n]", string1);

//INPUT END


//LOGIC START
    int length = 0;
    while(string1[length] != '\0') length++;

  int counter_array[200] = {0};
  for(int i = 0; i < length; i++){
    counter_array[tolower(string1[i])]+=1;
  }
//LOGIC END

//OUTPUT START
for(int i = 97; i < 123; i ++){
  printf("%c - %d\n",i,counter_array[i]);
}
//OUTPUT END


return 0;
}