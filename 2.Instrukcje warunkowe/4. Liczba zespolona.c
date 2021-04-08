#include <stdio.h>

int main()
{
    int r,u,correct;
    char sign;
    printf("Podaj liczbe zespolona: ");
    correct = scanf("%d%ci%d",&r,&sign,&u);
    if(correct != 3 || (sign!= '+'&& sign!='-')||u<0){
        printf("Incorrect input");
        return 1;
    }
    if(sign == '+')sign = ' ';
    printf("Czesc rzeczywista: %d\n",r);
    printf("Czesc urojona: %c%d",sign,u);

    return 0;
}
