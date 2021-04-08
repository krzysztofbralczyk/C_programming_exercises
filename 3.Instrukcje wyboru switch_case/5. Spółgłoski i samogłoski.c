#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int correct;
    char c;
    printf("Daj znac!\n");
    correct = scanf("%c",&c);
    
    switch(correct){
        case 0:
        printf("Incorrect input");
        return 1;
    }
    switch(isalpha(c)){
        case 0:
        printf("Incorrect input");
        return 1;
    }
    
    switch(tolower(c)){
        case 'a':
        printf("vowel");
        break;
        case 'u':
        printf("vowel");
        break;
        case 'e':
        printf("vowel");
        break;
        case 'i':
        printf("vowel");
        break;
        case 'o':
        printf("vowel");
        break;
        case 'y':
        printf("vowel");
        break;
        default:
        printf("consonant");
    }
    

    return 0;
}
