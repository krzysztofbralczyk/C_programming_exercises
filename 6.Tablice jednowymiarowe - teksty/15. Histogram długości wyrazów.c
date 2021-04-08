#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
//INPUT START
char string1[1002];
printf("Zarzuc stringa: ");
fgets(string1,1001,stdin);  
if(strlen(string1)>0 && string1[strlen(string1)-1] == '\n') string1[strlen(string1)-1] = '\0';
//INPUT END

//LOGIC START
int counters[1001] = {0};
int length;
for(int i = 0; (unsigned)i < (unsigned)strlen(string1); i++){
  if(isalpha(string1[i])){
    length = 1;
    while(isalpha(string1[i+1])){
      i++;
      length++;
    } 
    counters[length]++;

  }
}
//LOGIC END

//OUTPUT START
for(int i = 0; i < 1001 ; i++){
  if(counters[i] != 0){
    printf("%d - %d\n",i,counters[i]);
  }
}
//OUTPUT END
return 0;
}