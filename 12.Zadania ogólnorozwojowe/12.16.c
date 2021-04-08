#include <stdio.h>
#include <math.h>

int is_prime(unsigned long long a){
  if(a <= 1) return 0;
  if(a == 2) return 1;
  for(int i = 2; (unsigned)i < sqrt(a)+1; i++){
    if(a % (unsigned)i == 0) return 0;
  }
  return 1;
}

unsigned long long find_largest_prime_number(unsigned long long number){
    if(number < 10 && is_prime(number)) return number;

    unsigned long long divider = 1;
    unsigned long long biggest_prime = 0;

    do{
        divider *= 10;
        unsigned long long num_copy = number % divider;
        while(num_copy != 0){
            if(num_copy > biggest_prime && is_prime(num_copy)) biggest_prime = num_copy;
            num_copy = num_copy/10;
        }
    }while(number % divider != number);

    return biggest_prime;
}

int main(){
    unsigned long long int number;
    printf("Number please!!!: ");

    if(!scanf("%llu",&number)){
        printf("incorrect input");
        return 1;
    }
    
    printf("%llu",find_largest_prime_number(number));
    return 0;
}