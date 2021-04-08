#include <stdio.h>
#include <stdlib.h>

int main(){

    int* pt;
    pt = (int*)malloc(100*sizeof(int));
    if(pt == NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i = 0; i < 100; i++){
        *(pt+i) = i;
    }
    for(int i = 0; i < 100; i++){
        printf("%d ",*(pt+i));
    }

    free(pt);

    return 0;
}