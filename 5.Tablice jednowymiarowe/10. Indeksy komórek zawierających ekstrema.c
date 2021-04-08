#include <stdio.h>
#include <ctype.h>
int main()
{
    int i = 0, a= 0,tab[101],length = 0,min = 0,max = 0,flag = 1,sum=0,correct = 0;
    printf("Podaj dane:\n");
    for(i=0;i<101;i++){
        correct = scanf("%d",&a);
        
        if(a == -1||length==100){
            break;
        }
        if(!correct){
            printf("Incorrect input");
            return 1;
        }
        
        tab[i] = a;
        length++;
        sum += tab[i];
        if(flag){
            min = tab[i];
            max = tab[i];
            flag = 0;
        }
        if(min > tab[i]){
            min = tab[i];
        }
        if(max < tab[i]){
            max = tab[i];
        }
    }
    printf("%d\n%d\n%d\n%f\n%d\n",length,min,max,(float)sum/length,sum);
    for(i=0;i<length;i++){
        if (tab[i]==min){
            printf("%d ",i);
        }
    }
    printf("\n");
    for(i=0;i<length;i++){
        if (tab[i]==max){
            printf("%d ",i);
        }
    }
    return 0;
    
}