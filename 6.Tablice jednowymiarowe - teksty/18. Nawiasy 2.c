#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
//INPUT START
char string1[51];
printf("Zarzuc stringa: ");
scanf("%50[^\n]", string1);
//INPUT END


//LOGIC START
  //BIGGEST DENSITY FINDER START
int length = 0;
while(string1[length] != '\0') length++;

int counter = 0;
for(int i = 0; i < length; i++){
  if(string1[i] == '(') counter++;
  if(string1[i] == ')') counter--;
  if(counter < 0){
    printf("Niepoprawny");  
    return 0;
  } 
}
//LOGIC END

//OUTPUT START
if (counter == 0)printf("Poprawny");
else printf("Niepoprawny");
//OUTPUT END
return 0;
}