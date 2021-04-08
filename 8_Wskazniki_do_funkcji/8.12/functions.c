#include "functions.h"

typedef void (*functype)(void);
void print_chicken(void){
    printf(" MM\n");
    printf("<' \\___/|\n");
    printf("  \\_  _/\n");
    printf("    ][\n");
}
void print_egg(void){
    printf("  .~~~.\n");
    printf(" /     \\\n");
    printf("(\\/\\/\\/\\)\n");
    printf(" \\     /\n");
    printf("  `~~~`\n");
}
void print_rabbit(void){
    // printf("\\\\   //\n");
    // printf(" )\\-/(\n");
    // printf(" /o o\\\n");
    // printf("( =T= )\n");
    // printf("/'---'\\\n");
    printf(" \\\\   //\n  )\\-/(\n  /o o\\\n ( =T= )\n /'---'\\\n");
}



void (**easter(int size, void(*func1)(void), void(*func2)(void), void(*func3)(void)))(void){
    if(size<= 0 || func1 == NULL || func2 == NULL || func3 == NULL) return NULL;
    functype* functions = (functype*)malloc(size*sizeof(functype));
    if(functions == NULL) return NULL;
    int num_1_to_3;
    for(int i = 0; i < size; i++){
        num_1_to_3 = rand() % 3 + 1;
        if(num_1_to_3 == 1){*(functions+i) = func1;}
        if(num_1_to_3 == 2){*(functions+i) = func2;}
        if(num_1_to_3 == 3){*(functions+i) = func3;}
    }
    return functions;
}