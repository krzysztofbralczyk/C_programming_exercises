#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    int counter[11] = {0,0,0,0,0,0,0,0,0,0,0},num = 1;
    printf("Zachecam do podania liczb:\n");
    while(num != -1){
        
        if(!scanf("%d",&num)){
            printf("Incorrect input");
            return 1;
        } 
        if(num <=10 && num >= 0) counter[num]++;
    }
    
    for(int i = 0;i<=10;i++){
        printf("%d - %d\n",i,counter[i]);
    }
    
    return 0;
}