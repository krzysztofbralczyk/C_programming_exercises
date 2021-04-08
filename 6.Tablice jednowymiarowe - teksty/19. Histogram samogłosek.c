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

//ERROR HANDLING1 START
int length = 0;
while(string1[length] != '\0') length++;

  for(int i = 0; i < length; i++){
      if( !isalpha( string1[i] ) && !(string1[i] == ' ') ){
        printf("Incorrect input");
        return 1;
      }
  }
//ERROR HANDLING1 END 

//LOGIC START
int counter = 0;
int vowels[1001] = {0};

for(int i = 0; i < length; i++){
  if(isalpha(string1[i])){
    counter = 0;
    if(tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y'){
        counter++;
    }
    while(isalpha(string1[i+1])){
      i++;
      if(tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y'){
        counter++;
      }
    }
    vowels[counter]++;
  }
  
}
//LOGIC END

//OUTPUT START
for(int i = 0;i < 1001; i++){
  if(vowels[i] != 0) printf("%d - %d\n",i,vowels[i]);
}
//OUTPUT END
return 0;
}