#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int generate(int lotto[], int N, int start, int end){
    if(start>end || N < 1 || end-start+1<N) return -1;

    static unsigned int call_count = 0;
    srand(call_count + time(0));
    call_count++;

    int lotto_current_length = 0;
    for(int i = 0; i < N; i++){

        int a = rand()%(end-start+1) + start;

        int a_is_not_duplicate = 1;
        for(int j = 0; j < lotto_current_length; j++){
            if(lotto[j] == a) a_is_not_duplicate = 0;
        }
        if(a_is_not_duplicate){
            lotto[i] = a;
            lotto_current_length++;
        } else{
            i--;
        }
        
    }
    return 0;
}

void display_vector(const int vec[], int size) {
	if (size < 1) return;
	for (int i = 0; i < size; i++) {
		printf("%d ", vec[i]);
	}
	// printf("\n");
}

int main(){
    int A[6] = {0};
    generate(A,6,0,49);
    display_vector(A,6);

    return 0;
}
