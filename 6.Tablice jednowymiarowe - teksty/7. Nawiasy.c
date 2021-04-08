#include <stdio.h>

int main()
{
    printf("Daj nawias:\n");
    char bracets[50];
    scanf("%51[^\n]", bracets);
    
    int i = 0;
    while ( bracets[++i] != '\0');     // moze mi Pan wytlumaczyc czemu ten kod jest w stanie poprawnie policzyc ilosc wprowadzonyc elementow, mimo ze wychodza one po za tablice? jesli input to ()()(()()()((()))()(()())()()((())((())))(())()(())()()) , czyli 56 elementow, 'i' po zakonczeniu petli wynosi 56, efektywnie znajdujac szesc elementow i terminator ktore sa po za tablica o wielkosci 50.
    // printf("%d",i);

    if(i > 50){
        printf("Input is too long");
        return 1;
    }

    
    int depth = 0,max_depth = 0;
    
    for(int j = 0; j < i; j++){
        if (bracets[j] == '('){
            depth++;
            if (depth > max_depth) max_depth = depth;
        }
        else depth--;
    }   

    printf("%d ",max_depth);
    
    int index = -1;


    for(int j = 0; j < i; j++){
        if (bracets[j] == '('){
            depth++;
            index++;
            if (depth == max_depth) printf("%d ",index); 
        } else {
            depth--;
            index++;
        }
    }
    return 0;
}