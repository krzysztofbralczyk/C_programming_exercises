#include <stdio.h>

int main()
{
    
    double num = 0,counter = 0,sum = 0,min=0,max=0;
    
    printf("Podaj do pieciu liczb:\n");
    
    scanf("%lf",&num);
    if(num == -1) goto printuj;
    min = num;
    max = num;
    sum += num;
    counter++;
    
    scanf("%lf",&num);
    if(num == -1)goto printuj;
    if(min>num)min = num;
    if(max<num)max = num;
    sum += num;
    counter++;
    
    scanf("%lf",&num);
    if(num == -1)goto printuj;
    if(min>num)min = num;
    if(max<num)max = num;
    sum += num;
    counter++;
    
    scanf("%lf",&num);
    if(num == -1)goto printuj;
    if(min>num)min = num;
    if(max<num)max = num;
    sum += num;
    counter++;
    
    scanf("%lf",&num);
    if(num == -1)goto printuj;
    if(min>num)min = num;
    if(max<num)max = num;
    sum += num;
    counter++;

    printuj:
    printf("%.2lf\n%.2lf\n%.2lf",min,max,sum*1.0/counter);
    return 0;
}