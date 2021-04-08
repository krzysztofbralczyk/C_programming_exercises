#include <stdio.h>

int main()
{
    
    int A[26];

    for(int i = 0; i < 26; i++){
        A[i] = i+65;
    }

    for(int i = 0; i < 26; i++){
        printf("%d %c %c\n",A[i],A[i],A[i]+32);
    }

    return 0;
}