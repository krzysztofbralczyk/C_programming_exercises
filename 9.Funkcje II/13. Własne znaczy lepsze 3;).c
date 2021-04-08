#include <math.h>
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int my_itoa(int a, char tab[], int size){

    for(int i = 0; i < size; i++){    //czyszczenie tablicy
        tab[i] = '\0';
    }
    
//OGARNIECIE ZERA NA WEJSCIU START
    if(a == 0){
        if(size >= 2){
            tab[0] = '0';
            return 0;
        } else {
            return 1;
        }
    }
//OGARNIECIE ZERA NA WEJSCIU END

//OGARNIECIE MINUSA START- jesli a jest ujemne, zapamietaj ze jest ujemne i zamien liczbe na dodatnia
    int negative = 0;
    int num;
    if(a<0){                   
        negative = 1;
        num = -a;
    } else num = a;
//OGARNIECIE MINUSA END

    int i = 0;
    while(num != 0){
        if(i > size-2) return 1; //-2 zamiast -1 by uwzglednic terminator (chyba? test jednostkowy tak chce)
        tab[i] = num%10 + '0';
        i++;
        num /= 10;
    }

    if(negative){     //OGARNIECIE MINUSA pt.2
        if(i > size-2) return 1; //-2 zamiast -1 by uwzglednic terminator (chyba? test jednostkowy tak chce)
        tab[i] = '-';
        i++;
    }

    for(int j = 0; j < i/2; j++){
        int temp = tab[j];
        tab[j] = tab[i-1-j];
        tab[i-1-j] = temp;
    }
    return 0;

}
int my_ftoa(float a, int precision, char tab[], int size){
    if(size-2<precision || precision < 0) return 1; //-1 kropka -1 pierwsza liczba

    for(int i = 0; i < size; i++){    //czyszczenie tablicy
        tab[i] = '\0';
    }

//OGARNIECIE ZERA NA WEJSCIU START
    if(a == 0){
        if(size >= 3+precision){ //liczby precyzji + kropka + zero wiodace + terminator
            tab[0] = '0';
            tab[1] = '.';
            for (int i = 0; i < precision; i++){
                tab[2+i] = '0';
            }
            return 0;
        } else {
            return 1;
        }
    }
//OGARNIECIE ZERA NA WEJSCIU END
    
//OGARNIECIE MINUSA START- jesli a jest ujemne, zapamietaj ze jest ujemne i zamien liczbe na dodatnia
    int negative = 0;
    double double_num;
    if(a<0){                   
        negative = 1;
        double_num = -a;
    } else double_num = a;
//OGARNIECIE MINUSA END
    unsigned long long int num;
    num = double_num*pow(10,precision);

    int i = 0;
    while(num != 0){
        if(i > size-2){
            printf("It got activated");
            return 1;
        } //-1 terminator/ -1 bo index nie length
        tab[i] = num%10 + '0';
        i++;
        if(i == precision){
            tab[i] = '.';
            i++;
        }
        num /= 10;
    }

    if(negative){     //OGARNIECIE MINUSA pt.2
        if(i > size-2) return 1; //-1 terminator/ -1 bo index nie length
        tab[i] = '-';
        i++;
    }

    for(int j = 0; j < i/2; j++){
        int temp = tab[j];
        tab[j] = tab[i-1-j];
        tab[i-1-j] = temp;
    }
    return 0;
}


int main(){

    printf("Prosze o liczbe zmiennoprzecinkowa: ");
    double number_to_be_converted;
    if(!scanf("%lf",&number_to_be_converted)){
        printf("Incorrect input");
        return 1;
    }
    char A[20];
    char B[20];
    if(my_itoa(number_to_be_converted,A,20) == 1){
        printf("Incorrect input");
        return 1;
    }
    if(my_ftoa(number_to_be_converted,4,B,20) == 1){
        printf("Incorrect input");
        return 1;
    }

    for (int i = 0; A[i] != '\0'; i++) {
		printf("%c", A[i]);
	}
    printf("\n");

    for (int i = 0; B[i] != '\0'; i++) {
		printf("%c", B[i]);
	}
    return 0;
}
