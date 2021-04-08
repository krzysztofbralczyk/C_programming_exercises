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

int print_primes_rec(int x1, int x2, int no_primes) {
    if (x1 > x2){            //base case
        if(no_primes){
            printf("Nothing to show");      
            return 1;
        } else {
            return 0;
        }
    }
    if(is_prime_rec(x1,2)){
        no_primes = 0;
        printf("%d ",x1);
    }
    return print_primes_rec(x1+1,x2,no_primes);

}

int main() {
    printf("x1 prosze:  ");
    int x1;
    if(!scanf("%d",&x1)){
        printf("Incorrect input");
        return 1;
    }

    printf("x2 prosze:  ");
    int x2;
    if(!scanf("%d",&x2)){
        printf("Incorrect input");
        return 1;
    }

    if(x1 > x2){
        printf("Incorrect input");
        return 1;
    }

    int nothing_to_show = print_primes_rec(x1,x2,1);
    if(nothing_to_show) return 2;



	return 0;
}