#include <stdio.h>

int main()
{
    int num,correct,a,b,c,flag;
    printf("Liczba! prosze:\n");
    correct = scanf("%d",&num);
    a = num>0;
    b = num==0;
    c = num<0;
    flag = correct + 5*a+10*b+15*c;
    switch(flag){
        case 5:
        case 10:
        case 15:
        printf("incorrect input");
        return 1;
        
        case 6:
        printf("%d is positive",num);
        break;
        case 11:
        printf("%d is equal to 0",num);
        break;
        
        case 16:
        printf("%d is negative",num);
        
    }

    return 0;
}
