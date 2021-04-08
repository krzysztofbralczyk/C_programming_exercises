#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    
//INPUT START
    char string1[101];
    printf("Zarzuc stringa: ");
    scanf("%101[^\n]", string1);
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

    if(length > 100){        
        printf("Input is too long");
        return 2;
    }
//ERROR HANDLING1 END 

//LOGIC START
    char out_string[201];
    int out_str_counter = 0;
    for(int i = 0; i < length; i++){
        if(isupper(string1[i])){
            out_string[out_str_counter] = string1[i];
            out_str_counter++;
            out_string[out_str_counter] = string1[i];
            out_str_counter++;
            out_string[out_str_counter] = string1[i];
            out_str_counter++;
        }
        else{
            out_string[out_str_counter] = string1[i];
            out_str_counter++;
        }
    }

//LOGIC END

//ERROR HANDLING2 START
    if(out_str_counter > 200){        
        printf("Output is too long");
        return 3;
    }
    
//ERROR HANDLING2 END 

//OUTPUT START
    for(int i = out_str_counter-1; i>=0; i--){
        printf("%c", out_string[i]);
    }
//OUTPUT END
    return 0;
}