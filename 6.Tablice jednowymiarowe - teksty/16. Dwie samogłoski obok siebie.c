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

int counter = 0,flag;
for(int i = 0; i < length; i++){
  if(isalpha(string1[i])){
    flag = 1;
    while(isalpha(string1[i+1])){
      if(flag && (tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y') && (tolower(string1[i+1]) == 'a' || tolower(string1[i+1]) == 'e' || tolower(string1[i+1]) == 'i' || tolower(string1[i+1]) == 'o' || tolower(string1[i+1]) == 'u' || tolower(string1[i+1]) == 'y')){
        counter++;
        flag = 0;
      }
      i++;
    } 
  }
}
//LOGIC END

//OUTPUT START
 printf("%d",counter);
//OUTPUT END
return 0;
}