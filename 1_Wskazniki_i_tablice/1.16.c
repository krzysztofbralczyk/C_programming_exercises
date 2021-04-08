#include <stdio.h>
#include <math.h>
int is_prime(int a);

int main(){
    int prime_numbers[10][10] = {{0}};
    printf("Liczby prosze: ");

    for(int counter = 0, number; counter < 100;){
        
        if(!scanf("%d",&number)){
            printf("Incorrect input");
            return 1;
        }

        if(is_prime(number)){
            *(*(prime_numbers+(counter/10))+(counter%10)) = number;
            counter++;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i%3 == 0 && j%3 == 0){
                printf("%d ",*(*(prime_numbers+i)+j));
            }
        }
    }

    return 0;
}

int is_prime(int a){
  if(a <= 1) return 0;
  if(a == 2) return 1;
  for(int i = 2; i < sqrt(a)+1; i++){
    if(a % i == 0) return 0;
  }
  return 1;
}


