#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main(){
    struct doubly_linked_list_t* list = dll_create();
    if(list == NULL){printf("Failed to allocate memory"); return 8;}

    int operation = 999;
    do{
        printf("Co chcesz zrobic?: ");
        int scanf_returned = scanf("%d",&operation);
        if(scanf_returned != 1){printf("Incorrect input"); dll_clear(list);free(list); return 1;}
        if(operation < 0 || operation > 14){printf("Incorrect input data\n"); continue;}

        if(operation == 0){
            break;

        } else if(operation == 1) {
            printf("Podaj liczbe: ");
            int num;
            if(!scanf("%d",&num)){printf("Incorrect input"); dll_clear(list); free(list); return 1;}
            int push_returned = dll_push_back(list,num);
            if(push_returned == 2){printf("Failed to allocate memory"); dll_clear(list); free(list); return 8;}

        } else if(operation == 2){
            int error_code;
            int pop_returned = dll_pop_back(list,&error_code);
            if(error_code == 1) {printf("List is empty\n"); continue;}
            printf("%d\n", pop_returned);

        } else if(operation == 3){
            printf("Podaj liczbe: ");
            int num;
            if(!scanf("%d",&num)){printf("Incorrect input"); dll_clear(list); free(list); return 1;}
            int push_returned = dll_push_front(list,num);
            if(push_returned == 2){printf("Failed to allocate memory"); dll_clear(list); free(list); return 8;}
            
        } else if(operation == 4){
            int error_code;
            int pop_returned = dll_pop_front(list,&error_code);
            if(error_code == 1) {printf("List is empty\n"); continue;}
            printf("%d\n", pop_returned);

        } else if(operation == 5){
            printf("Podaj liczbe: ");
            int num;
            if(!scanf("%d",&num)){printf("Incorrect input"); dll_clear(list); free(list); return 1;}
            printf("Podaj index: ");
            int idx;
            if(!scanf("%d",&idx)){printf("Incorrect input"); dll_clear(list); free(list); return 1;}

            int insert_returned = dll_insert(list,idx,num);
            if(insert_returned == 2){printf("Failed to allocate memory"); dll_clear(list); free(list); return 8;}
            if(insert_returned == 1){printf("Index out of range\n"); continue;}

        } else if(operation == 6){
            if(dll_is_empty(list)){printf("List is empty\n"); continue;}
            printf("Podaj index: ");    
            int idx;
            int error_code;
            if(!scanf("%d",&idx)){printf("Incorrect input"); dll_clear(list); free(list); return 1;}
            int remove_returned = dll_remove(list,idx,&error_code);
            if(error_code == 1){ printf("Index out of range\n"); continue;}
            printf("%d\n",remove_returned);

        } else if(operation == 7){
            if(dll_is_empty(list)){printf("List is empty\n"); continue;}
            int error_code;
            printf("%d\n",dll_back(list,&error_code));

        } else if(operation == 8){
            if(dll_is_empty(list)){printf("List is empty\n"); continue;}
            int error_code;
            printf("%d\n",dll_front(list,&error_code));

        } else if(operation == 9){
            if(dll_is_empty(list)) {printf("1\n"); continue;}
            else {printf("0\n"); continue;}

        } else if(operation == 10){
            printf("%d\n",dll_size(list));

        } else if(operation == 11){
            dll_clear(list);
        } else if(operation == 12){
            if(dll_is_empty(list)){printf("List is empty\n"); continue;}
            printf("Podaj index: ");
            int idx;
            int error_code;
            if(!scanf("%d",&idx)){printf("Incorrect input"); dll_clear(list); free(list); return 1;}
            int at_returned = dll_at(list,idx,&error_code);
            if(error_code == 1){ printf("Index out of range\n"); continue;}
            printf("%d\n",at_returned);

        } else if(operation == 13){
            if(dll_is_empty(list)){printf("List is empty\n"); continue;}
            dll_display(list);
            printf("\n");

        } else if(operation == 14){
            if(dll_is_empty(list)){printf("List is empty\n"); continue;}
            dll_display_reverse(list);
            printf("\n");
        }

    } while(operation != 0);

    dll_clear(list);
    free(list);
    return 0;
}
