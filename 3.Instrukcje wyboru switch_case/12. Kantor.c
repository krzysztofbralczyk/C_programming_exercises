#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int correct;
    char c;
    double kwota;
    printf("Daj kwote!\n");
    correct = scanf("%lf",&kwota);
    
    switch(correct){
        case 0:
        printf("Incorrect input");
        return 1;
    }
    
    switch(kwota<0){
        case 1:
        printf("Incorrect input");
        return 1;
    }
    
    printf("Daj znac!\n");
    correct = scanf(" %c",&c);
    
    switch(correct){
        case 0:
        printf("Incorrect input");
        return 1;
    }
    
    switch(c){
        case 'e':
        printf("%.2lf",(double)kwota/4.2074);
        break;
        
        case 'f':
        printf("%.2lf",(double)kwota/4.7073);
        break;
        
        case 'd':
        printf("%.2lf",(double)kwota/3.5382);
        break;
        
        default:
        printf("Incorrect input");
        return 1;
    }
    
    
    return 0;
}
