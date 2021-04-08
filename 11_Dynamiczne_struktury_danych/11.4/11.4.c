#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"
// #include "stack.c"

int main(int argc, char* argv[]) {
    if (argc < 2) { printf("Not enough arguments"); return 9; }

    //no idea why dante refuses to open file
    // void* test = malloc(1190);
    // if(test == NULL){printf("Failed to allocate memory"); return 8;}
    // free(test);
    //no idea why dante refuses to open file

    for (int i = 1; i < argc; i++) {
        struct stack_t* stack = NULL;
        // char* temp = (char*)malloc((strlen(*(argv + i)) + 1 + 4) * sizeof(char));
        // if(temp == NULL){printf("Failed to allocate memory"); return 8;}
        // // for(unsigned int j = 0; j < strlen(*(argv + i)) + 4; j++) *(temp+j) = '\0';
        // *temp = '\0';
        // strcat(temp,*(argv + i));
        // strcat(temp,".txt");
        // printf("|%s|",temp);
        int load_returned = stack_load(&stack, *(argv + i));
        if (load_returned == 2) { printf("Couldn't open file %s\n", *(argv + i));  continue; }
        if (load_returned == 3) { printf("Failed to allocate memory");   return 8; }
        int save_returned = stack_save(stack, *(argv + i));
        if (save_returned == 2) { printf("Couldn't create file"); stack_destroy(&stack);  return 5; }
        printf("File %s saved\n", *(argv + i));
        stack_destroy(&stack);
       
    }
    return 0;
}
