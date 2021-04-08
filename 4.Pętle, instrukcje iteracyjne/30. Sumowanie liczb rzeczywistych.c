#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    double sum = 0,random_num;
    int n,correct;
    
    printf("podaj liczbe: ");
    correct = scanf("%d",&n);
    
    if(!correct || n > 10 || n < 1){
        printf("Improper input data");
        return 1;
    }
    
    srand(time(NULL));

    for(int i = 0;i < n;i++){
        random_num = ((double)rand()/((double)RAND_MAX+1))*10-5;
        printf("%lf\n",random_num);
        sum += random_num;
    }
    printf("%.4lf",sum);
    

    return 0;
}