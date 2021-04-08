#include <stdio.h>

int main(void)
{
    int correct,amount;
    double netto;
    printf("Zachecam do podania ilosci zuzytej energii elektrycznej:\n");
    correct = scanf("%d",&amount);
    
    if(!correct || amount < 0) {
        printf("Incorrect input");
        return 1;
    }
    
    if (amount <= 50)
    {
        netto = amount * 0.50;
    } 
    else if (amount <=150)
    {
        netto =50*0.50 + (amount-50) * 0.75;
    } 
    else if (amount <=250)
    {
        netto =50*0.50 + 100*0.75 + (amount-150) * 1.20;
    }
    else
    {
        netto =50*0.50 + 100*0.75 + 100*1.20 + (amount-250)*1.50;
    }
    
    printf("%lf",netto*1.22);
    
	return 0;
}