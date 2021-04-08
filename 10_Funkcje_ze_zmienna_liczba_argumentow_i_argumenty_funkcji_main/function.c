#include "function.h"

unsigned long long int bits_to_number(int *err_code, int N, ...){
    if(N <= 0 || N > 64) if(err_code!=NULL) {*err_code = 1; return 777;}

    va_list args;
    va_start(args,N);
    unsigned long long int sum = 0;

    for(int i = 0; i < N; i++){
        int num = va_arg(args, int);
        if(num != 0 && num != 1) if(err_code!=NULL) {*err_code = 1; va_end(args); return 777;}
        sum = sum*2 + num;

    }

    va_end(args);
    if(err_code != NULL)*err_code = 0;
    return sum;
}