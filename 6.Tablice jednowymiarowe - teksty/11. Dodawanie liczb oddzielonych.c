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
        if( !isdigit( string1[i] ) && !(string1[i] == '|') && !(string1[i] == '-') ){
            printf("Incorrect input");
            return 1;
        }
    }
//ERROR HANDLING1 END 

//LOGIC START
  long int current_sum = 0;
  long int sums[1000];
  int sums_index = 0;

  for(int i = 0; i < length; i++){
    if(isdigit(string1[i])){
        current_sum += atol(&string1[i]);
        while(isdigit(string1[i+1])) i++;
        if(i == (length-1)){
          sums[sums_index] = current_sum;
          sums_index++;
          break;
    }
        // printf("current sum: %d\n",current_sum); //checker
    }
    else if(string1[i] == '|' || i == (length-1)){
      sums[sums_index] = current_sum;
      // printf("current sum: %d\n",current_sum); //checker
      current_sum = 0;
      sums_index++;
    }
  }
//LOGIC END

//OUTPUT START
  for(int i = 0; i < sums_index; i++){
    printf("%li ",sums[i]);
  }
//OUTPUT END
return 0;
}