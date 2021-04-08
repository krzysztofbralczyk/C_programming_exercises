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
    if( !isalpha( string1[i] ) && !(string1[i] == ' ')){
        printf("Incorrect input");
        return 1;
    }
}
//ERROR HANDLING1 END 

//LOGIC START
  //BIGGEST DENSITY FINDER START
int counter_vowel = 0,counter_letter = 0;
double max_counter = 0.0;
for(int i = 0; i < length; i++){
  if(isalpha(string1[i])){
    counter_letter = 1;
    counter_vowel = 0;
    if((tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y')){
        counter_vowel++;
      }
    while(isalpha(string1[i+1])){
      i++;
      counter_letter++;
      if((tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y')){
        counter_vowel++;
      }
    }
    if(max_counter<(double)counter_vowel/counter_letter)max_counter=(double)counter_vowel/counter_letter;
  }
}
  // printf("%lf", max_counter); /debugging
  //BIGGEST DENSITY FINDER END

  //DENSEST WORDS FINDER START
  int dense_words[1000];
  int dense_words_counter = 0;
  int starting_idx;
  for(int i = 0; i < length; i++){
  if(isalpha(string1[i])){
    starting_idx = i;
    counter_letter = 1;
    counter_vowel = 0;
    if((tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y')){
        counter_vowel++;
      }
    while(isalpha(string1[i+1])){
      i++;
      counter_letter++;
      if((tolower(string1[i]) == 'a' || tolower(string1[i]) == 'e' || tolower(string1[i]) == 'i' || tolower(string1[i]) == 'o' ||tolower (string1[i]) == 'u' || tolower(string1[i]) == 'y')){
        counter_vowel++;
      }
    }
    if(max_counter == (double)counter_vowel/counter_letter){
      // printf("%lf %d %d\n",max_counter,counter_vowel,counter_letter);   //debugging
      dense_words[dense_words_counter] = starting_idx;
      // printf("%d\n",starting_idx); //debugging
      dense_words_counter++;
    }
  }
}
  //DENSEST WORDS FINDER END
//LOGIC END

//OUTPUT START
int j;
for(int i = dense_words_counter-1; i >= 0; i--){
  j = dense_words[i];
  while(isalpha(string1[j])){
    printf("%c",string1[j]);
    j++;
  }
  printf("\n");
}

//OUTPUT END
return 0;
}