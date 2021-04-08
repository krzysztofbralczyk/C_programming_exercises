#include <stdio.h>

int main()
{
    int A[5][10];
    printf("TEKST ZACHETY!!!!!!!!:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 10; j++){
            if(!scanf("%d",&A[i][j])){
                printf("\nincorrect input");
                return 1;
            }
        }
    }
    int B[10][5];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            B[i][j] = A[j][i];
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
        printf("%d ",B[i][j]);
        }
        printf("\n");
    }

  return 0;
}