#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"
// #include "circular_buffer.c"

int main(){
    
    printf("Gimme size of the buffor: ");
    int buffor_size = 0;
    if(!scanf("%d", &buffor_size)){
        printf("Incorrect input");
        return 1;
    }
    if(buffor_size <= 0){
        printf("Incorrect input data");
        return 2;
    }

    struct circular_buffer_t* pointer_to_struct;
    struct circular_buffer_t** pointer_to_pointer_to_struct = &pointer_to_struct;
    if(circular_buffer_create_struct(pointer_to_pointer_to_struct,buffor_size) == 2){
        printf("Failed to allocate memory");
        return 8;
    }
    int choice;
    printf("Choose your destiny: ");
    if(!scanf("%d",&choice)){
        printf("Incorrect input");
        circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
        return 1;
    }
    int number = 12345;
    int err_code;
    int *err_code_pt = &err_code;    
    while(choice != 0){

        if(choice<0 || choice>6){
            printf("Incorrect input data\n");
            printf("Choose your destiny: ");
            if(!scanf("%d",&choice)){
                printf("Incorrect input");
                circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
                return 1;
            }
            continue;
        }

        if(choice == 1){
            printf("Gimme number: ");
            if(!scanf("%d",&number)){
                printf("Incorrect input");
                circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
                return 1;
            }
            circular_buffer_push_back(pointer_to_struct,number);
        }
        if(choice == 2){
            number = circular_buffer_pop_back(pointer_to_struct,err_code_pt);
            if(err_code == 2){
                printf("Buffer is empty\n");
                printf("Choose your destiny: ");
                if(!scanf("%d",&choice)){
                    printf("Incorrect input");
                    circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
                    return 1;
                }
                continue;
            }
            printf("%d\n", number);
        }
        if(choice == 3){
            number = circular_buffer_pop_front(pointer_to_struct,err_code_pt);
            if(err_code == 2){
                printf("Buffer is empty\n");
                printf("Choose your destiny: ");
                if(!scanf("%d",&choice)){
                    printf("Incorrect input");
                    circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
                    return 1;
                }
                continue;
            }
            printf("%d\n", number);
        }
        if(choice == 4){
            if(circular_buffer_empty(pointer_to_struct)) printf("Buffer is empty\n");
            circular_buffer_display(pointer_to_struct);
        }
        if(choice == 5){
            printf("%d\n",circular_buffer_empty(pointer_to_struct));
        }
        if(choice == 6){
            printf("%d\n",circular_buffer_full(pointer_to_struct));
        }


        printf("Choose your destiny: ");
        if(!scanf("%d",&choice)){
            printf("Incorrect input");
            circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
            return 1;
        }
    }


    circular_buffer_destroy_struct(pointer_to_pointer_to_struct);
    return 0;
}