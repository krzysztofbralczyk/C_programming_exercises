#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
DEFINE_ARRAY(int)
DEFINE_ARRAY(double)
CREATE_ARRAY(int)
CREATE_ARRAY(double)
FREE_ARRAY(int)
FREE_ARRAY(double)
SAVE_ARRAY(int)
SAVE_ARRAY(double)
LOAD_ARRAY(int)
LOAD_ARRAY(double)
SORT_ARRAY(int)
SORT_ARRAY(double)

int main(){
    char* filename = (char*)malloc(30*sizeof(char));
    if(filename == NULL){
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Enter filename: ");
    if(!scanf("%29s",filename)){
        printf("Incorrect input");
        return 1;
    }

    printf("Choose number type: ");
    int type;
    if(!scanf("%d",&type)){
        printf("Incorrect input");
        free(filename);
        return 1;
    }
    if(type != 0 && type != 1){
        printf("Incorrect input data");
        free(filename);
        return 2;
    }

    int load_returned, save_returned;
    if(type == 0){   
        struct array_int_t* array;  
        load_returned = load_array_int(&array,filename);
        if(load_returned == 2){printf("Couldn't open file"); free(filename); return 4;}
        if(load_returned == 3){printf("File corrupted"); free(filename); return 6;}
        if(load_returned == 4){printf("Failed to allocate memory"); free(filename); return 8;}

        sort_array_int(array);
        save_returned = save_array_int(array,filename);
        if(save_returned == 2){printf("Couldn't create file"); free(filename);free_array_int(array); return 5;}
        free_array_int(array);
    } else {
        struct array_double_t* array;
        load_returned = load_array_double(&array,filename);
        if(load_returned == 2){printf("Couldn't open file"); free(filename); return 4;}
        if(load_returned == 3){printf("File corrupted"); free(filename); return 6;}
        if(load_returned == 4){printf("Failed to allocate memory"); free(filename); return 8;}
        sort_array_double(array);
        save_returned = save_array_double(array,filename);
        if(save_returned == 2){printf("Couldn't create file"); free(filename); free_array_double(array); return 5;}
        free_array_double(array);
    }
    printf("File saved");
    free(filename);
    return 0;
}