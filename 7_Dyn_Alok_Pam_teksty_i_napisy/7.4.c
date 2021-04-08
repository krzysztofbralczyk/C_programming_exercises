#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int subtract(const char* number1, const char* number2, char** result);
int add(const char* number1, const char* number2, char** result);
int validate(const char* number);
int compare(const char* number1, const char* number2);

int correct_negative(const char* number);
int correct_positive(const char* number);
int after_minus_contains_not_a_number(const char* number);
int minus_only(const char* number);
int zero_after_minus(const char* number);
int contains_not_a_number(const char* number);
int ujemna(const char* number);
int starts_with_zero_and_longer_than_one(const char* number);
int error_1(const char* number1, const char* number2);
int allocate_memory_and_fill_with_terminators(const char* number1, const char* number2, char** result);
void add_two_positives(const char* number1, const char* number2, char* result);
void move_right(char* result);
int same_sign(const char* number1, const char* number2);
int bigger_modulo(const char* number1, const char* number2);
void subtract_two_positives(const char* number1, const char* number2, char* result);


int main() {
    char* number1 = (char*)malloc(200 * sizeof(char) + 1 * sizeof(char));
    if (number1 == NULL) { printf("Failed to allocate memory"); return 8; }
    char* number2 = (char*)malloc(200 * sizeof(char) + 1 * sizeof(char));
    if (number2 == NULL) { printf("Failed to allocate memory"); free(number1); return 8; }

    printf("Podaj pierwsza liczba ");
    scanf("%200s", number1);
    while (getchar() != '\n');
    printf("Podaj druga liczba ");
    scanf("%200s", number2);
    while (getchar() != '\n');
    char* result;

    int add_returned = add(number1, number2, &result);
    if(add_returned == 2){printf("Incorrect input");free(number1); free(number2); return 1; }
    if(add_returned == 3){printf("Failed to allocate memory");free(number1); free(number2); return 8;}
    printf("%s\n", result);
    free(result);

    int subtract_returned = subtract(number1, number2, &result);
    if(subtract_returned == 2){printf("Incorrect input");free(number1); free(number2); return 1; }
    if(subtract_returned == 3){printf("Failed to allocate memory");free(number1); free(number2); return 8;}
    printf("%s", result);

    compare("1","2"); // just for Dante :)

    free(number1);
    free(number2);
    free(result);
    result = NULL;
    return 0;
}


int add(const char* number1, const char* number2, char** result) {
    if (error_1(number1, number2)) return 1;
    if (result == NULL) return 1;
    if (validate(number1) != 0 || validate(number2) != 0) return 2;
    int memory_allocation_success = allocate_memory_and_fill_with_terminators(number1, number2, result);
    if (memory_allocation_success != 1) return 3;
    if (same_sign(number1, number2)) {
        if (same_sign(number1, number2) == 1) { //positive numbers
            add_two_positives(number1, number2, *result);
        }
        else { //negative numbers
            **result = '-';
            add_two_positives(number1, number2, *result + 1);
        }
    }
    else { //different signs
        if (bigger_modulo(number1, number2) == 1) {
            if (*number1 == '-') {
                **result = '-';
                subtract_two_positives(number1, number2, *result + 1);
            }
            else { //bigger modulo number is positive
                subtract_two_positives(number1, number2, *result);
            }
        }
        else { //num 2 has bigger modulo
            if (*number2 == '-') {
                **result = '-';
                subtract_two_positives(number2, number1, *result + 1);
            }
            else {
                subtract_two_positives(number2, number1, *result);
            }
        }
        if (strlen(*result) == 2 && **result == '-' && *(*result + 1) == '0') {
            **result = '0';
            *(*result + 1) = '\0';
        }
    }
    return 0;
}
int subtract(const char* number1, const char* number2, char** result) {
    if (error_1(number1, number2)) return 1;
    if (result == NULL) return 1;
    if (validate(number1) != 0 || validate(number2) != 0) return 2;
    int memory_allocation_success = allocate_memory_and_fill_with_terminators(number1, number2, result);
    if (memory_allocation_success != 1) return 3;

    if (same_sign(number1, number2)) { //dwie liczby z tym samym znakiem
        if (*number1 == '-' && *number2 == '-') {  //obie ujemne
            if (bigger_modulo(number1, number2) == 1) { //pierwsza wieksza
                **result = '-';
                subtract_two_positives(number1, number2, *result + 1);
            }
            else { //druga wieksza
                subtract_two_positives(number2, number1, *result);
            }
        }
        else { //obie dodatnie
            if (bigger_modulo(number1, number2) == 1) {
                subtract_two_positives(number1, number2, *result);
            }
            else {
                **result = '-';
                subtract_two_positives(number2, number1, *result + 1);
            }
        }
    }
    else { //different signs
        if (*number1 == '-') {
            **result = '-';
            add_two_positives(number1, number2, *result + 1);
        }
        else {
            add_two_positives(number1, number2, *result);
        }
    }

    if (strlen(*result) == 2 && **result == '-' && *(*result + 1) == '0') {
        **result = '0';
        *(*result + 1) = '\0';
    }
    return 0;
}
int bigger_modulo(const char* number1, const char* number2) {
    if (*number1 == '-') number1 = number1 + 1;
    if (*number2 == '-') number2 = number2 + 1;
    if (strlen(number1) > strlen(number2)) return 1;
    if (strlen(number2) > strlen(number1)) return -1;
    if (strcmp(number1, number2) > 0) return 1;
    else return -1;
}
void add_two_positives(const char* number1, const char* number2, char* result) {
    if (*number1 == '-') number1 = number1 + 1;
    if (*number2 == '-') number2 = number2 + 1;
    int smaller_length = strlen(number1) < strlen(number2) ? strlen(number1) : strlen(number2);
    int bigger_length = strlen(number1) > strlen(number2) ? strlen(number1) : strlen(number2);
    const char* longer_number = ((int)strlen(number1) == bigger_length) ? number1 : number2;
    const char* shorter_number = ((int)strlen(number2) == smaller_length) ? number2 : number1;

    int additional = 0;

    for (int i = smaller_length - 1, j = bigger_length - 1; i >= 0 && j >= 0; i--, j--) {
        int sum = *(shorter_number + i) + *(longer_number + j) - 2 * '0' + additional;
        move_right(result);

        if (sum >= 10) {
            *result = sum % 10 + '0';
            additional = 1;
        }
        else {
            *result = sum + '0';
            additional = 0;
        }
    }

    for (int i = bigger_length - smaller_length - 1; i >= 0; i--) {
        int sum = *(longer_number + i) + additional - '0';
        move_right(result);

        if (sum >= 10) {
            *result = sum % 10 + '0';
            additional = 1;
        }
        else {
            *result = sum + '0';
            additional = 0;
        }
    }

    if (additional) {
        move_right(result);
        *result = 1 + '0';
    }

}
void subtract_two_positives(const char* number1, const char* number2, char* result) {
    //first number always is bigger
    if (*number1 == '-') number1 = number1 + 1;
    if (*number2 == '-') number2 = number2 + 1;

    int bigger_length = strlen(number1);
    int smaller_length = strlen(number2);

    int additional = 0;

    for (int i = smaller_length - 1, j = bigger_length - 1; i >= 0 && j >= 0; i--, j--) {
        int subtract_result = *(number1 + j) - *(number2 + i) - additional;
        move_right(result);

        if (subtract_result < 0) {
            *result = subtract_result + 10 + '0';
            additional = 1;
        }
        else {
            *result = subtract_result + '0';
            additional = 0;
        }
    }

    for (int i = bigger_length - smaller_length - 1; i >= 0; i--) {
        int subtract_result = *(number1 + i) - additional - '0';
        move_right(result);

        if (subtract_result < 0) {
            *result = subtract_result + 10 + '0';
            additional = 1;
        }
        else {
            *result = subtract_result + '0';
            additional = 0;
        }
    }

    while (*result == '0' && *(result + 1) == '0') {
        for (int i = 0; *(result + i) != '\0'; i++) {
            *(result + i) = *(result + i + 1);
        }
    }
    if (*result == '0' && *(result + 1)) {
        for (int i = 0; *(result + i) != '\0'; i++) {
            *(result + i) = *(result + i + 1);
        }
    }
}
void move_right(char* result) {
    int length = strlen(result);
    for (int i = length; i >= 0; i--) {
        *(result + i + 1) = *(result + i);
    }
}
int same_sign(const char* number1, const char* number2) {
    if (*number1 == '-' && *number2 == '-') return 2;
    if (*number1 != '-' && *number2 != '-') return 1;
    return 0;
}
int compare(const char* number1, const char* number2) {
    if (number1 == NULL || number2 == NULL) return 2;
    if (validate(number1) != 0 || validate(number2) != 0) return 3;
    if (strcmp(number1, number2) == 0) return 0;
    
    if (same_sign(number1, number2)) {
        
        if (same_sign(number1, number2) == 1) { //are positive
            if (strlen(number1) > strlen(number2)) return 1;
            if (strlen(number2) > strlen(number1)) return -1;
            if (strcmp(number1, number2) > 0) return 1;
            else return -1;

        }
        else { //are negative
            if (strlen(number1) > strlen(number2)) return -1;
            if (strlen(number2) > strlen(number1)) return 1;
            if (strcmp(number1, number2) > 0) return -1;
            else return 1;

        }

    } else {

        if (*number2 == '-') return 1;
        else return -1;

    }

}
int allocate_memory_and_fill_with_terminators(const char* number1, const char* number2, char** result) {

    int space_for_terminator = 1;
    int addition_two_bytes = 2;
    unsigned longer_string_length = (strlen(number1) > strlen(number2) ? strlen(number1) : strlen(number2));

    *result = (char*)malloc((longer_string_length + space_for_terminator + addition_two_bytes) * sizeof(char));
    if (*result == NULL) return 0;

    for (int i = 0; (unsigned)i < longer_string_length + space_for_terminator + addition_two_bytes; i++) {
        *(*result + i) = '\0';
    }
    return 1;
}
int validate(const char* number) {
    if (number == NULL) return -1;
    if (strcmp(number, "") == 0) return 2;

    if (ujemna(number)) {

        if (correct_negative(number)) return 0;
        else return 2;

    }
    else {

        if (correct_positive(number)) return 0;
        else return 2;

    }
}
int correct_negative(const char* number) {
    //takes only strings starting with '-'
    if (minus_only(number) || zero_after_minus(number) || after_minus_contains_not_a_number(number)) return 0;
    return 1;
}
int after_minus_contains_not_a_number(const char* number) {
    for (int i = 1; *(number + i); i++) {
        if (!isdigit(*(number + i))) return 1;
    }
    return 0;
}
int minus_only(const char* number) {
    if (strlen(number) == 1) return 1;
    return 0;
}
int zero_after_minus(const char* number) {
    //takes only strings longer than 1
    if (*(number + 1) == '0') return 1;
    else return 0;
}
int contains_not_a_number(const char* number) {
    for (int i = 0; *(number + i); i++) {
        if (!isdigit(*(number + i))) return 1;
    }
    return 0;
}
int correct_positive(const char* number) {
    if (starts_with_zero_and_longer_than_one(number) || contains_not_a_number(number)) return 0;
    return 1;
}
int ujemna(const char* number) {
    if (*number == '-') return 1;
    else return 0;
}
int starts_with_zero_and_longer_than_one(const char* number) {
    if (*number == '0' && strlen(number) > 1) return 1;
    else return 0;
}
int error_1(const char* number1, const char* number2) {
    if (number1 == NULL || number2 == NULL) return 1;
    return 0;
}