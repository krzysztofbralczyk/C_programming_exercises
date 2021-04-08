
#include <stdio.h>

int main()
{
    int a,b,c,d,e;
    printf("Podaj numer telefonu w formacie w formacie (dd) ddd-dd-dd:");
    e = scanf("(%d) %d-%d-%d",&a,&b,&c,&d);
    if(e == 4)
    {
        printf("Number kierunkowy:%02d\n",a);
        printf("Numer telefonu:%03d-%02d-%02d",b,c,d);
        return 0;
    }
    else 
    {
        printf("Incorrect input");
        return 1;
    }
    
    
}
