#include <stdio.h>
#include <ctype.h>

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace);

int main(){
    printf("Text please: ");
    char text[1001];
    scanf("%1000[^\n]",text);
    // text[70] = 12;
    int upp_counter = 0;
    int low_counter = 0;
    int space_counter = 0;
    marks_counter(text,&upp_counter,&low_counter,&space_counter);

    printf("%d\n%d\n%d",upp_counter,low_counter,space_counter);


    return 0;
}

int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace){
    if(text == NULL || uppercase == NULL || lowercase == NULL || whitespace == NULL) return 1;
    *lowercase = 0;
    *uppercase = 0;
    *whitespace = 0;

    for(int i = 0; *(text + i)!= '\0'; i++){

        char current_char = *(text+i);
        if(isspace(current_char) && current_char!= 11 && current_char != 12 && current_char !=13){(*whitespace)++;}
        if(islower(current_char)){(*lowercase)++;}
        if(isupper(current_char)){(*uppercase)++;}

    }
    return 0;
}