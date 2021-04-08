#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"
// #include "doubly_linked_list.c"

int main(){
    struct doubly_linked_list_t* list = dll_create();
    if(list == NULL){printf("Failed to allocate memory"); return 8;}

    printf("Enter list (-1 when done): ");
    int num;
    int flag = 1;
    do {
        if (!scanf("%d", &num)) { printf("Incorrect input"); dll_clear(list); free(list); return 1; }
        if (flag == 1 && num == -1) { printf("Not enough data available"); dll_clear(list); free(list); return 3; }
        if (num != -1) {
            int push_returned = dll_push_back(list, num);
            if (push_returned == 2) { printf("Failed to allocate memory"); dll_clear(list); free(list); return 8; }
        }
        flag = 0;
    } while (num != -1);
    
    printf("Choose sorting (0 or 1): ");
    if(!scanf("%d",&num)){printf("Incorrect input"); dll_clear(list);free(list);return 1;}
    if(num < 0 || num > 1){printf("Incorrect input data"); dll_clear(list); free(list);return 2;}

    if(num == 0)dll_sort_asc(list);
    if(num == 1)dll_sort_desc(list);
    dll_display(list);
    printf("\n");
    dll_display_reverse(list);
    

    dll_clear(list);
    free(list);
    return 0;
}
