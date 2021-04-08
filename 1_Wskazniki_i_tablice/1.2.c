#include <stdio.h>

int main(){
    int number;
    int *num_pointer;
    
    number = 1;
    num_pointer = &number;

    printf("%d %d %p\n",number,*num_pointer,(void *)num_pointer);

    *num_pointer = 5;

    printf("%d %d %p",number,*num_pointer,(void *)num_pointer);

    return 0;
}