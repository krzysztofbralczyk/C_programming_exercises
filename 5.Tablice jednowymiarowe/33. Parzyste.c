
#include <stdio.h>

int main()
{
    int etab[4],otab[6],num,e=0,o=0,e1=0,o1=0;
    
    printf("10 liczb prosze:\n");
    
    for(int i = 0; i < 10; i++){
        
        if(!scanf("%d",&num)){
            printf("Incorrect input");
            return 1;
        }
        
        if(num % 2 == 0) {
            etab[e] = num;
            e++;
        }else{
            otab[o] = num;
            o++;
        }
    }
    if(e!=4||o!=6){
        printf("Incorrect input data");
        return 2;
    }
    
    for(int i = 0; i < 10; i++){
        if(i == 0 || i == 3|| i == 6|| i == 9){
            printf("%d ",etab[e1]);
            e1++;
        } else{
            printf("%d ",otab[o1]);
            o1++;
        }
        
    }
    
    return 0;
}
