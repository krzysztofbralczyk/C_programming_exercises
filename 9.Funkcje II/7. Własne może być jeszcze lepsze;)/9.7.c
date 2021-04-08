#include <stdio.h>
#include "action.h"
#include "tested_declarations.h"
#include "rdebug.h"

int alpha_is_not_number(int number){
    if (number < '0' || number > '9') return 1;
    else return 0;
}
int alpha_is_number(int number){
    if (number < '0' || number > '9') return 0;
    else return 1;
}

int my_atoi_ex(const char tab[], enum action continuation){
    if(continuation != START && continuation != CONTINUE) return 0;
    int result = 0;
    int negat_posit_switch = 1;
    static int i = 0;
    int searching_for_number = 1;
    if(!continuation) i = 0;


    for(;tab[i] != '\0';i++){
        if(searching_for_number){
            if( alpha_is_not_number(tab[i])   &&   !(tab[i] == '-' && alpha_is_number(tab[i + 1]))) continue;

            if(tab[i] == '-'){
                negat_posit_switch = -1;
                continue;
            }
        }
        searching_for_number = 0;
        
        if(alpha_is_not_number(tab[i])) break;
        result = result * 10 + tab[i] - '0';

    }

    return result * negat_posit_switch;

}

float my_atof_ex(const char tab[], enum action continuation){
    if(continuation != START && continuation != CONTINUE) return 0;

	double result = 0.0;
	int negat_posit_switch = 1;
	int secondCycle = 0;
    int searching_for_number = 1;
	static int i = 0;
    if(!continuation) i = 0;

    for(;tab[i] != '\0'; i++){
        if(searching_for_number){
            if( alpha_is_not_number(tab[i])   &&   !(tab[i] == '-' && alpha_is_number(tab[i + 1]))) continue;

            if(tab[i] == '-'){
                negat_posit_switch = -1;
                continue;
            }
        }
        searching_for_number = 0;

        if (tab[i] == '.') {
            secondCycle = 1;
            i++;
            break;
        }
        if(alpha_is_not_number(tab[i])) break;


        result = result * 10 + tab[i] - '0';
    }
    
	if (secondCycle) {
		double divider = 10.0;
		for (; tab[i] != '\0'; i++) {
            if(alpha_is_not_number(tab[i])) break;
			result += (double)(tab[i] - (double)'0') / divider;
			divider *= 10.0;
		}
	}

	return negat_posit_switch * (float)result;
}



int main(){
    printf("Ciag znakow prosze:  "); //input1
    char A[101] = {0};                       
    scanf("%100[^\n]",A);
    while(getchar()!='\n');

    int nothing_to_show = 1;
    int int_sum = 0;
    for(int i = 0; A[i]!='\0'; i++){
        int a = my_atoi_ex(A,CONTINUE);
        if(a != 0) nothing_to_show = 0;
        int_sum += a;
    }
    if(nothing_to_show){
        printf("Nothing to show");
        return 0;
    }
    printf("%d\n",int_sum);

    float float_sum = 0;
    for(int i = 0; A[i]!='\0'; i++){
        float_sum += my_atof_ex(A,CONTINUE);
    }
    printf("%.4f",float_sum);


    return 0;
}
