#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[1002];
    printf("Podaj teksta wacium Panie:\n");
    fgets(text,1002,stdin);
    
    int j = 0,counter = 0,a = 1,e = 1,o = 1,u = 1,i = 1,y = 1,A = 1, E = 1, O = 1, U = 1, I = 1, Y = 1;
    while(text[j] != '\0'){
        
        if (text[j] == 'e' && e==1){
            counter++;
            e = 0;
        } 
        if (text[j] == 'a' && a==1){
            counter++;
            a = 0;
        }
        if(text[j] == 'u' && u==1){
            counter++;
            u = 0;
        }
        if(text[j] == 'i' && i==1){
            counter++;
            i = 0;
        }
        if(text[j] == 'y' && y==1){
            counter++;
            y = 0;
        }
        if(text[j] == 'o' && o==1){
            counter++;
            o = 0;
        }
        if (text[j] == 'E' && E==1){
            counter++;
            E = 0;
        } 
        if (text[j] == 'A' && A==1){
            counter++;
            A = 0;
        }
        if(text[j] == 'U' && U==1){
            counter++;
            U = 0;
        }
        if(text[j] == 'I' && I==1){
            counter++;
            I = 0;
        }
        if(text[j] == 'Y' && Y==1){
            counter++;
            Y = 0;
        }
        if(text[j] == 'O' && O==1){
            counter++;
            O = 0;
        }
        j++;
    }
    printf("%d", counter);
    return 0;
}