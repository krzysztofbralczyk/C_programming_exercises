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
        if(!isalpha(string1[i]) && !(string1[i]==' ')){
            printf("Incorrect input");
            return 1;
        }
    }
//ERROR HANDLING1 END 

//LOGIC START
  //LONGEST WORD FINDER START
    int counter = 0;
    int max_counter = 0;
    for(int i = 0; i < length; i++){
        if(string1[i]!=' ' && i!=length-1){
            counter++;
        }
        else if(i==length-1 && string1[i]!=' '){
            counter++;
            if(counter>max_counter)max_counter = counter;
        }
        else{
            if(counter>max_counter)max_counter = counter;
            counter = 0;  
        }
    }
    //LONGEST WORD FINDER END
  
    //LONGEST WORD COUNTER START
    counter = 0;
    int big_words_counter = 0;
    for(int i = 0; i < length; i++){
        if(string1[i]!=' ' && i!=length-1){
            counter++;
        }
        else if(i==length-1 && string1[i]!=' '){
            counter++;
            if(counter == max_counter) big_words_counter++;
        }
        else{
            if(counter == max_counter) big_words_counter++;
            counter = 0;           
        }
    }
    //LONGEST WORD COUNTER END
//LOGIC END

//OUTPUT START
    counter = 0;
    printf("%d %d\n",big_words_counter,max_counter);
    
    for(int i = length-1; i >= 0 ; i--){
        if(string1[i] != ' ' && i != 0){
            counter++;
        }
        else if(i == 0 && string1[i] != ' '){
            counter++;
            if(counter == max_counter){
                for(int j = 0; j<max_counter; j++){
                    printf("%c",string1[i+j]);
                }
                printf("\n");
            }
            counter = 0;
        }
        else{
            if(counter == max_counter){
                for(int j = 0; j<max_counter; j++){
                    printf("%c",string1[i+1+j]);
                }
                printf("\n");
            }
            counter = 0;           
        }
    }
//OUTPUT END
    return 0;
}