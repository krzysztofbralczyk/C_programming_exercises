
#include <stdio.h>

int main()
{
    int num/*,correct*/;
    printf("Number please:\n");
    /*correct = */scanf("%d",&num);
    
    // switch(correct)
    // {
    //     case 0:
    //     printf("Incorrect input");
    //     return 1;
    // }
    switch(num)
    {
        case 1:
        printf("Brak promocji do nastepnej klasy");
        break;
        
        case 2:
        case 3:
        case 4:
        case 5:
        printf("Promocja do nastepnej klasy");
        break;
        
        case 6:
        printf("Promocja z ocena celujaca");
        break;
        
        default:
        printf("Wprowadzona ocena jest niepoprawna");
    }

    return 0;
}