#include <stdio.h>
#include <string.h>
#include <ctype.h>

int add(const char* number1, const char* number2, char* result, int size);
int validate(const char* number);
void move_right(char* result);

int main() {
    printf("Podaj liczbe: ");
    char strin1[201];   
    scanf("%200[^\n]",strin1);
    while(getchar() != '\n');

    printf("Podaj liczbe: ");
    char strin2[201];   
    scanf("%200[^\n]",strin2);

    if( validate(strin1) != 1 || validate(strin2) != 1){
        printf("Incorrect input");
        return 1;
    }
    char result[202];
    add(strin1, strin2, result, 202);
    printf("%s", result);
    return 0;
}

int add(const char* number1, const char* number2, char* result, int size) {
    if (number1 == NULL || number2 == NULL || result == NULL || size <= 0) return 1;
    for(int i = 0; *(number1+i); i++) if(!isdigit(*(number1+i))) return 1;
    for(int i = 0; *(number2+i); i++) if(!isdigit(*(number2+i))) return 1;

    int smaller_length = strlen(number1) < strlen(number2) ? strlen(number1) : strlen(number2);
    int bigger_length = strlen(number1) > strlen(number2) ? strlen(number1) : strlen(number2);
    const char* longer_number = ((int)strlen(number1) == bigger_length) ? number1 : number2;
    const char* shorter_number = ((int)strlen(number2) == smaller_length) ? number2 : number1;

    *result = '\0';
    int real_size = 1;
    int additional = 0;

    for(int i = smaller_length-1, j = bigger_length-1; i>=0 && j>=0; i--, j--){
        int sum = *(shorter_number + i) + *(longer_number + j) - 2 * '0' + additional;
        real_size++;
        if (real_size > size) return 2;
        move_right(result);

        if(sum >= 10){
            *result = sum%10 + '0';
            additional = 1;
        } else {
            *result = sum + '0';
            additional = 0;
        }
    }
    
    for(int i = bigger_length-smaller_length-1; i>=0; i--){
        int sum = *(longer_number+i)+additional - '0';
        real_size++;
        if(real_size > size) return 2;
        move_right(result);

       if(sum >= 10){
           *result = sum%10 + '0';
            additional = 1;
        } else {
            *result = sum + '0';
            additional = 0;
        }
    }

    if(additional){
        real_size++;
        if (real_size > size) return 2;
        move_right(result);
        *result = 1 + '0';
    }

    return 0;
}

void move_right(char* result) {
    int length = strlen(result);
    for (int i = length; i >= 0; i--) {
        *(result + i + 1) = *(result + i);
    }
}

int validate(const char* number) {
    if (number == NULL) return -1;
    if (*number == '0' && strlen(number) > 1) return 0;
    for (int i = 0; *(number + i); i++) {
        if (!isdigit(*(number + i))) {
            return 0;
        }
    }
    return 1;
}