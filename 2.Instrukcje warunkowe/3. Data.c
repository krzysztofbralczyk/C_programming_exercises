
#include <stdio.h>
// #include <time.h>
// #include <string.h>

int main()
{
    
    
        printf("Podaj date (w formacie dd-mm-yyyy):");
        int a,b,c,correct_input;
        correct_input = scanf("%02d-%02d-%04d",&a,&b,&c);
        
        if(correct_input != 3)
        {
            printf("Incorrect input");
            return 1;
        }
        
        else if(a<1 || a>31 || b<1 || b>12 ||((b==4||b==6||b==9||b==11) && a > 30))
        {
            printf("Incorrect");
            return 0;
        }
        
        else if(b==2 && a>28 && !(c % 400 == 0 || (c % 4 == 0 && c % 100 != 0)))
        {
            printf("Incorrect");
            return 0;
        }

        else
        {
            printf("Correct");
            return 0;
        }
    
    // time_t raw_time;                           /// create variable of time_t type (num of seconds from 1970 to now)
    // time(&raw_time);                         /// get current time in seconds and using time function, save it in raw_time variable
    // char current_time[30];                      /// declare array/string where You will put current time as string
    // strcpy(current_time,ctime(&raw_time));   /// call ctime to change raw_time(in sec) into date, then use strcpy to copy result into current_time
    // printf("%s",current_time);                ///print string current_time
    // int day,month,year;
    // memcpy() TO NIE O TO CHODZILO!!!! ARRRRRRRGGGGGHHHHHH!

    

}