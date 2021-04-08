#include <stdio.h>

int main(){
    printf("How many numbers do you want?: ");
    int how_many;
    if(scanf("%d",&how_many) != 1){
        printf("Incorrect input");
        return 1;   
    }
    // printf("%f",how_many);
    if(how_many >100 || how_many<1){
        printf("Incorrect input data");
        return 2;
    }
    printf("Your numbers plase: ");
    float T[100];
    float *useless_pointer_that_i_have_to_use_instead_of_T = T;

    int i = 0;
    for(; i < how_many; i++){

        float get_number;

        if(!scanf("%f",&get_number)){
            printf("Incorrect input");
            return 1;
        }

        *(useless_pointer_that_i_have_to_use_instead_of_T+i) = get_number;
    }
    i--; //T+i point to last table element now

    float sum = 0.0;
    for(int j = i; j>=0; j--){
        printf("%f ",*(useless_pointer_that_i_have_to_use_instead_of_T+j));
        sum += *(useless_pointer_that_i_have_to_use_instead_of_T+j);
    }
    float average = sum/(i+1);
    printf("\nSuma: %.2f\nSrednia: %.2f",sum,average);
    

    return 0;
}