#include <stdio.h>

int sum_of_digits(long long number, int flag){  //zwraca co druga liczbe, flaga zmienia czy bierzemy od pierwszej czy od drugiej
 //base case start
    if(number / 10 == 0 && flag) {
        return ((number>0) ? number : -number) % 10;         //zwraca liczbe (dodaje pierwsza)
    } 
    
    else if(number / 10 == 0 && !flag) return 0;             //zwraca liczbe (nie dodaje pierwszej)
//base case end

//recursive case start
    else if(flag){
        flag = !flag;
        return ((number > 0) ? number : -number) % 10 + sum_of_digits(number/10,flag);
        
    } 
    else{
        flag = !flag;
        return sum_of_digits(number/10,flag);
    }
//recursive case end
} 


int is_divisible_by_11(int number){
    if(((number>0) ? number : -number) < 10){
        if (number % 10 == 0) return 1;
        else return 0;
    }
    else return (is_divisible_by_11(sum_of_digits(number,1) - sum_of_digits(number,0)));
}

int main(){

    printf("Liczbe do sprawdzenia prosze: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(is_divisible_by_11(num)){
        printf("YES");
    } else {
        printf("NO");
    }
 
    return 0;
}

// Uwaga W programie nie wolno używać zmiennych globalnych.
// Uwaga W programie nie wolno używać słowa kluczowego static.
// Uwaga W programie nie wolno używać pętli.
// Uwaga W programie nie wolno korzystać z biblioteki math.
// Uwaga W programie nie wolno korzystać z operatora modulo oraz dzielenia, za wyjątkiem dzielenia przez 10.