#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    printf("zachecam:");
    
    char string[101],out_string[201];
    
    scanf("%100s",string);  
    int j = 0; 
    while(string[j]!= '\0') j++;

    int c = 0;
    while(getchar()!='\n') c++;
    if(c > 0) {
        printf("Input is too long");
        return 2;
    }     
    if(j>0){ //aby clang sie nie czepial
        if(isdigit(string[j-1])){              //if last char is number, output error
            printf("Incorrect input");
            return 1;
        }
    }
    
    
    for(int i = 0; i<j-1; i++){
        if(isdigit(string[i]) && isdigit(string[i+1])){
            printf("Incorrect input");
            return 1;
        }
    }
    
    
    int out_str_counter = 0;
    for(int i = 0; i < j; i++){
        if(string[i]>='0' && string[i]<='9'){
            for(int j = 0; j < atoi(&string[i]); j++){
                out_string[out_str_counter] = string[i+1];
                out_str_counter++;
                if(out_str_counter>200){
                    printf("Output is too long");
                    return 3;
                }
            }
            i++;
        }
        else{
            out_string[out_str_counter] = string[i];
            out_str_counter++;
            if(out_str_counter>200){
                printf("Output is too long");
                return 3;
            }
        }
    }
    
    for(int i = out_str_counter-1;i >= 0;i--){
        printf("%c",out_string[i]);
    }
    
    
    
 


    return 0;
}