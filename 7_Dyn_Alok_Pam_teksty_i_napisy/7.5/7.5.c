#include "big_numbers.h"
// #include "big_numbers.c"
int main(){
    struct big_numbers_t* A;
    if(create_big_numbers(&A,10)==2){printf("Failed to allocate memory"); return 8;}
    char* big_number = (char*)malloc(201*sizeof(char));
    if(big_number == NULL){printf("Failed to allocate memory"); destroy_big_numbers(&A); return 8;}

    printf("Big numba please: ");

    while (1){
        *big_number = getchar();
        if(*big_number == '\n') break;
        scanf("%199s",big_number+1);
        if(strcmp(big_number,"") == 0) break;
        if(validate(big_number) == 2){printf("Incorrect input\n");while(getchar()!='\n'); continue;}
        int add_result = add_big_number(A,big_number);
        if(add_result == 3){printf("Buffer is full\n"); break;}
        if(add_result == 2){printf("Failed to allocate memory\n"); break;}
        while(getchar()!='\n');
    }
    
    if(A->size == 0)printf("Buffer is empty");
    else display(A);


    free(big_number);
    destroy_big_numbers(&A);
    return 0;
}
