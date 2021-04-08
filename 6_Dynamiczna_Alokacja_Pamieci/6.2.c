#include <stdio.h>
#include <stdlib.h>

int main(){

    float* pt;
    pt = (float*)malloc(sizeof(float));
    if(pt == NULL){
        printf("Failed to allocate memory");
        return 8;
    }
    
    *pt = 3.14159265359;
    printf("%lf %p",*pt,(void*)pt);

    free(pt);

    return 0;
}