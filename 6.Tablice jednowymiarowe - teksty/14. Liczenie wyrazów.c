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

int counter = 0;
for(int i = 0; i < length; i++){
  if(isalpha(string1[i])){
    counter++;
    while(isalpha(string1[i+1])) i++;
  }
}
//LOGIC END

//OUTPUT START
printf("%d",counter);
//OUTPUT END
return 0;
}