#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int main()
{
    int age,correct;
    char gender[20];

    printf("Wiek!\n");
    correct = scanf("%d",&age);
    if(!correct || age<1){
        printf("Incorrect input");
        return 1;
    }
    
    printf("Plec!\n");
    correct = scanf("%19s",gender);
    if(!correct){
        printf("Incorrect input");
        return 1;
    }
    
    if(strcmp(gender,"kobieta")&&strcmp(gender,"mezczyzna")){
        printf("Incorrect input");
        return 1;
    }

    
    if (!strcmp(gender,"kobieta")){
        if(age<=3)printf("1300");
        if(age>3 && age <= 6)printf("1700");
        if(age>6 && age <= 9)printf("2100");
        if(age>9 && age <= 12)printf("2300");
        if(age>12 && age <= 15)printf("2600-2800");
        if(age>15 && age <= 20)printf("2500-2700");
        if(age>20 && age <= 59)printf("2400-2800");
        if(age>59 && age <= 75)printf("2200");
        if(age>75)printf("2000");
    }
    else{
        if(age<=3)printf("1300");
        if(age>3 && age <= 6)printf("1700");
        if(age>6 && age <= 9)printf("2100");
        if(age>9 && age <= 12)printf("2600");
        if(age>12 && age <= 15)printf("3000-3300");
        if(age>15 && age <= 20)printf("3200-3700");
        if(age>20 && age <= 64)printf("2800-3200");
        if(age>64 && age <= 75)printf("2300");
        if(age>75)printf("2100");  
    }
    
    
    return 0;
}