#include <stdio.h>

int is_prime_rec(int number, int divider) {
    if(divider < 2) return is_prime_rec(number, 2);//ujemne dzielniki sprowadz do 2

    if(number < 2) return 0;         //jesli liczba jest mniejsza od dwoch, napewno nie jest primem

    if(number == 2 || number == 3) return 1; //dwojka i trojka to prime'y ( ulatwia to dalsza czesc)

    if(divider > number / 2) return is_prime_rec(number, 2);   //dzielniki wieksze od polowy sprowadz do 2
    
    if (number % divider == 0) return 0;      //jesli liczba jest podzielna przez divider zwroc 0

    if (divider == number / 2 ) return 1;        //jesli divider dojdzie do polowy numeru to liczba jest primem
	
	else return is_prime_rec(number, divider + 1);   //jesli nic nie zostalo aktywowane powtorz z wiekszym dzielnikiem
}

int is_superprime_rec(int num){
    if (num == 0) return 0;
    if((is_prime_rec(num/10,2) || num/10 == 0) && is_prime_rec(num,2)) return 1;
    else{
        if(is_prime_rec(num,2)) return is_superprime_rec(num/10);
        else return 0;
    }
}

int main(){

    printf("Liczbe do sprawdzenia prosze: ");
    int num;
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }

    if(is_superprime_rec(num)){
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}