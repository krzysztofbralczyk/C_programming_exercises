#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct point_t
{
    int x;
    int y;
};
int show(int);
int my_printf(char*,...);
int my_scanf(char*,...);


int main(){

    return 0;
}
int my_scanf(char* string,...){
    if(string == NULL) return 777;
    va_list args;
    va_start(args,string);
    int counter = 0;

    for(char* text = string; *text != '\0'; text++){
        while(*text != '%' && *text != '\0'){
            text++;
        }
        text++;
        if(*text == 'd'){
            int* number = va_arg(args,int*);
            int flag_negative = 0;
            *number = 0;
            char letter = getchar();
            while(isspace(letter)) letter = getchar();
            if(!isdigit(letter) && letter != '-') {va_end(args); return counter;}
            if(letter == '-'){flag_negative = 1;letter = getchar();}
            if(!isdigit(letter)) {va_end(args); return counter;}
            while(isdigit(letter)){
                *number = 10*(*number) + (letter - '0');
                letter = getchar();
            }
            if(flag_negative)*number = -(*number);
            counter++;
        }
        else if(*text == 'f'){
            double* number = va_arg(args,double*);
            int flag_negative = 0;
            *number = 0;
            char letter = getchar();
            while(isspace(letter)) letter = getchar();
            if(!isdigit(letter) && letter != '-') {va_end(args); return counter;}
            if(letter == '-'){flag_negative = 1;letter = getchar();}
            if(!isdigit(letter)) {va_end(args); return counter;}
            while(isdigit(letter)){
                *number = 10*(*number) + (letter - '0');
                letter = getchar();
            }
            counter++;
            if(letter != '.'){if(flag_negative)*number = -(*number); va_end(args); return counter;};
            letter = getchar();
            if(!isdigit(letter)){if(flag_negative)*number = -(*number); va_end(args); return counter;};
            unsigned long long int d_counter = 10;
            while(isdigit(letter)){
                (*number) += (double)(letter - '0')/d_counter;
                d_counter *= 10;
                letter = getchar();
            }
            if(flag_negative)*number = -(*number);
            
        }
        else if(*text == 'p'){
            struct point_t* point = va_arg(args,struct point_t*);
            int flag_negative_x = 0;
            int flag_negative_y = 0;
            point->x = 0;
            point->y = 0;

            char letter = getchar();
            while(isspace(letter)) letter = getchar();
            if(letter != '(') {va_end(args); return counter;}
            letter = getchar();
            if(!isdigit(letter) && letter != '-') {va_end(args); return counter;}
            if(letter == '-'){flag_negative_x = 1;letter = getchar();}
            if(!isdigit(letter)) {va_end(args); return counter;}
            while(isdigit(letter)){
                point->x = 10*(point->x) + (letter - '0');
                letter = getchar();
            }
            if(flag_negative_x)point->x = -(point->x);
            
            if(letter != ' ') {va_end(args); return counter;}
            counter++;
            letter = getchar();
            if(!isdigit(letter) && letter != '-') {va_end(args); return counter;}
            if(letter == '-'){flag_negative_y = 1;letter = getchar();}
            if(!isdigit(letter)) {va_end(args); return counter;}
            while(isdigit(letter)){
                point->y = 10*(point->y) + (letter - '0');
                letter = getchar();
            }
            if(flag_negative_y)point->y = -(point->y);
            counter++;
            if(letter != ')') {va_end(args); return counter;}
            

        }
        else break;

    }
    va_end(args);    
    return counter;
}
int my_printf(char* string,...){
    if(string == NULL) return 777;
    va_list args;
    va_start(args,string);
    int counter = 0;
    for(char* text = string; *text != '\0'; text++){
        while(*text != '%' && *text != '\0'){
            putchar(*text);
            counter++;
            text++;
        }
        text++;
        if(*text == 's') {
            char* string = va_arg(args, char*);
            while(*string != '\x0'){
                putchar(*string);
                counter++;
                string++;
            }
        }
        else if(*text == 'd') counter += show(va_arg(args,int));
        else if(*text == 'f'){
            double d_num = va_arg(args,double);
            if(d_num < 0){ d_num = -d_num; counter++; putchar('-');}
            int num = (int)d_num;
            counter += show(num);
            putchar('.');
            counter++;
            for(int i = 0; i < 5; i++){
                d_num = d_num*10;
                double copy = d_num;
                putchar((unsigned long long int)copy%10 + '0');
                counter++;
            }
        }
        else if(*text == 'p'){
            struct point_t point = va_arg(args,struct point_t);
            putchar('(');
            counter += show(point.x);
            putchar(' ');
            counter += show(point.y);
            putchar(')');
            counter += 3;
        }
        else break;
    }
    va_end(args);
    return counter;
}
int show(int num){
    int counter = 0;
    if(num == 0) {putchar('0'); return 1;}
    else{
        if(num<0){num = -num; putchar('-'); counter++;}
        int copy = num;
        int length = 0;
        while(copy != 0){copy /= 10; length++;}
        int length_copy = length;
        for(int i = 0; i < length_copy; i++){
            copy = num;
            copy /= (int)pow(10,--length);
            putchar(copy + '0');
            counter++;
            num = num%(int)pow(10,length);
        }
    }
    return counter;
}
