#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
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

int vector_max_norm(const int tab[], int size){
    int max = 0;
    for(int i = 0;i < size; i++){
        if(abs(tab[i])>abs(max)) max = tab[i]; 
    }
    return abs(max);
}
int vector_sum(const int tab[], int size){
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum+=tab[i];
    }
    return sum;
}

void display_vector(const int vec[], int size) {
	if (size < 1) return;
	for (int i = 0; i < size; i++) {
		printf("%d ", vec[i]);
	}
	// printf("\n");
}

int main(){

    int dolny_przedzial,gorny_przedzial,liczba_elementow_do_wylosowania;
    printf("\nPodaj dolny przedzial:  ");
    if(!scanf("%d",&dolny_przedzial)){
        printf("Incorrect input");
        return 1;
    }

    printf("\nPodaj gorny przedzial:  ");
    if(!scanf("%d",&gorny_przedzial)){
        printf("Incorrect input");
        return 1;
    }
    printf("\nPodaj liczbe elementow do wylosowania:  ");
    if(!scanf("%d",&liczba_elementow_do_wylosowania)){
        printf("Incorrect input");
        return 1;
    }

    if(liczba_elementow_do_wylosowania > 100){
        printf("incorrect input data");
        return 2;
    }

    int A[100] = {0};
    if(generate(A,liczba_elementow_do_wylosowania,dolny_przedzial,gorny_przedzial)==-1){
        printf("incorrect input data");
        return 2;
    }
    display_vector(A,liczba_elementow_do_wylosowania);
    printf("\nnorma max wynosi:  %d\n",vector_max_norm(A,liczba_elementow_do_wylosowania));
    printf("suma wynosi:  %d",vector_sum(A,liczba_elementow_do_wylosowania));
    return 0;
}
