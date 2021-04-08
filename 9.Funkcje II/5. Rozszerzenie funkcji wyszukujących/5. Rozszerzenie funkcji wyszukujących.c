#include <stdio.h>
#include "action.h"
#include "tested_declarations.h"
#include "rdebug.h"

int find_any_ex(const char tab[], const char tab2[], enum action zmienna_enum){
    if(zmienna_enum != START && zmienna_enum!= CONTINUE) return -1;
    static int l = 0;
    if(!zmienna_enum) l = 0;
    while(tab[l] != '\0'){
        int j = 0;
        while(tab2[j] != '\0'){
            if(tab[l] == tab2[j]){
                l++;
                return l-1;
            }
            j++;
        }
        l++;
    }
    return -1;
}
int find_char_ex(const char tab[], char c, enum action zmienna_enum){
    static int i = 0;
    if(!zmienna_enum) i = 0;
    while(tab[i] != '\0'){
        i++;
        if(tab[i-1] == c){
            return i-1;
        }
    }
    return -1;
}
int find_string_ex(const char tab[], const char tab2[], enum action zmienna_enum){
    if(zmienna_enum != START && zmienna_enum!= CONTINUE) return -1;
    static int k = 0;
    if(!zmienna_enum) k = 0;
    int idx_of_first_letter;
    while(tab[k] != '\0'){
        idx_of_first_letter = k;
        int j = 0;
        while(tab[k] == tab2[j]){
            k++;
            j++;
            if(tab2[j] == '\0') return idx_of_first_letter;
        }
        k++;
    }
    return -1;
}






int main(){

    printf("Ciag znakow prosze:  "); //input1
    char A[1001] = {0};                       
    scanf("%1000[^\n]",A);
    while(getchar()!='\n');

    printf("Drugi ciag znakow prosze:  "); //input2
    char B[1001] = {0};
    scanf("%1000[^\n]",B);
    while(getchar()!='\n');


    int a = find_char_ex(A,B[0],START); //output1
    if(a == -1) printf("Nothing to show");
    while(a != -1){
        printf("%d ",a);
        a = find_char_ex(A,B[0],CONTINUE);
    }
    printf("\n");

    int b = find_string_ex(A,B,START); //output2
    if(b == -1) printf("Nothing to show");
    while(b != -1){
        printf("%d ",b);
        b = find_string_ex(A,B,CONTINUE);
    }
    printf("\n");

    find_any_ex(A,B,START); //output3
    int c = find_any_ex(A,B,CONTINUE); 
    if(c == -1) printf("Nothing to show");
    else printf("%d",c);
    
    
    return 0;
}
