#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
//INPUT START
  char string1[101];
  printf("Zarzuc stringa: ");
  scanf("%100[^\n]", string1);
//INPUT END

//ERROR HANDLING1 START
    int length = 0;
    while(string1[length] != '\0') length++;

    for(int i = 0; i < length; i++){
        if( !isdigit( string1[i] ) && !(string1[i] == '+') && !(string1[i] == '-') ){
            printf("Incorrect input");
            return 1;
        }
    }
//ERROR HANDLING1 END 

//LOGIC START
  int sum = 0;

  for(int i = 0; i < length; i++){
    if( isdigit(string1[i]) && i == 0){
      sum += atoi(&string1[i]);
      while(isdigit(string1[i+1])) i++;
    }
    else if(string1[i] == '+'){
      sum += atoi(&string1[i+1]);
      while(isdigit(string1[i+1])) i++;
    }
    else if(string1[i] == '-'){
      sum -= atoi(&string1[i+1]);
      while(isdigit(string1[i+1])) i++;
    }
  }
//LOGIC END

//OUTPUT START

  printf("%d",sum);

//OUTPUT END
return 0;
}