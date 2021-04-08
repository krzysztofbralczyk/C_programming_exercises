#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
//INPUT START
  char string1[1001];
  int shift;
  printf("Zarzuc stringa: ");
  scanf("%1000[^\n]", string1); 
  printf("Zarzuc przesuniecie: ");
  scanf("%d",&shift);

//INPUT END

//LOGIC START
int length = 0;
while(string1[length] != '\0') length++;


for(int i = 0; i < length; i++){
  if(isupper(string1[i])){
    printf("%c",65+(string1[i]%65+shift)%26);
  }
  else if(islower(string1[i])){
    printf("%c",97+(string1[i]%97+shift)%26);
  }
  else if(string1[i] == ' '){
    printf(" ");
  }
}
//LOGIC END

//OUTPUT START

//OUTPUT END
return 0;
}