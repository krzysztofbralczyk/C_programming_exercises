
#include <stdio.h>

int main()
{
    int num,tab[100],i = 0;
    
    printf("Podaj liczby: ");
    
    if(!scanf("%d",&num)){
        printf("Incorrect input");
        return 1;
    }
    
    while(num!=-1 && i < 100){
        tab[i] = num;
        i++;
        if(!scanf("%d",&num)){
            printf("Incorrect input");
            return 1;
        }
    
    }
    
    if(i==0/* || i == 1*/){
        printf("not enough data available");
        return 2;
    }
    
    for(int j = 0;j < i;j++){
        if(!(tab[j] == tab[i-j-1])) {
            printf("NIE");
            return 0;
        }
    }
    printf("TAK");
    return 0;
}