#include <stdio.h>

int main(){

int T[10];
int *pointer_to_array = T;

for(int i = 0; i < 10; i++){
    *(pointer_to_array + i) = i;
}

for(int i =0; i< 10; i++){
    printf("%d ",*(pointer_to_array+i));
}
    
return 0;
}