#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

struct student_t
{
    char* name;
    char* surname;
    int index;
};
void destroy(struct student_t** s);
void show(const struct student_t* p);
struct student_t* read(int* err_code);
char* ltrim(char* text);

int main() {
    //Maximilian, SchellSchellSchellSchellSchellSchellSch, 209295
    struct student_t* p = (struct student_t*)malloc(sizeof(struct student_t) + 100);
    if (p == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    else {
        free(p);
        printf("Podaj dane studenta w formacie \'imie, nazwisko, numer indeksu\':\n");
    }
    int error_code;

    struct student_t* sp = read(&error_code);

    if (sp == NULL) {
        if(error_code == 4){
            printf("Failed to allocate memory");
            return 8;
        }
        else{
            printf("Incorrect input");
            return error_code;
        }
    }

    show(sp);
    destroy(&sp);


    return 0;

}

void destroy(struct student_t** s) {
    if (s == NULL) return;
    if ((*s)->name != NULL) free((*s)->name);
    if ((*s)->surname != NULL) free((*s)->surname);
    free(*s);
}
void show(const struct student_t* p) {
    if (p == NULL) return;
    printf("%s %s, %d", p->name, p->surname, p->index);
}
struct student_t* read(int* err_code) {
    struct student_t* p = (struct student_t*)malloc(sizeof(struct student_t));
    if (p == NULL) {
        if (err_code != NULL) *err_code = 4;
        return NULL;
    }
    //malloced 100 to pretend it's whole string
    char* data = (char*)malloc(100 * sizeof(char));
    if (data == NULL) {
        if (err_code != NULL) *err_code = 4;
        free(p);
        return NULL;
    }


    //get first word into data
    scanf("%99[^,^\n]", data);
    if (getchar() != ',') {
        if (err_code != NULL) *err_code = 1;
        free(p);
        free(data);
        return NULL;
    }
    strcpy(data, ltrim(data));

    p->name = (char*)malloc((strlen(data) + 1) * sizeof(char));
    if (p->name == NULL) {
        if (err_code != NULL) *err_code = 4;
        free(p);
        free(data);
        return NULL;
    }
    strcpy(p->name, data);
    for (int i = 0; i < 100; i++) {
        *(data + i) = '\0';
    }

    scanf("%99[^,^\n]", data);
    if (getchar() != ',') {
        if (err_code != NULL) *err_code = 2;
        free(p->name);
        free(data);
        free(p);
        return NULL;
    }
    strcpy(data, ltrim(data));
    p->surname = (char*)malloc((strlen(data) + 1) * sizeof(char));
    if (p->surname == NULL) {
        if (err_code != NULL) *err_code = 4;
        free(p->name);
        free(p);
        free(data);
        return NULL;
    }
    strcpy(p->surname, data);
    free(data);
    char num = getchar();
    while (!isdigit(num) && num != '\n') num = getchar();
    if (num == '\n') {
        if (err_code != NULL) *err_code = 3;

        free(p->name);
        free(p->surname);
        free(p);
        return NULL;
    }

    p->index = 0;
    while (isdigit(num)) {
        p->index = (p->index) * 10 + (num - '0');
        num = getchar();
    }


    if (err_code != NULL) *err_code = 0;

    return p;
}
char* ltrim(char* text) {
    if (text == NULL) return NULL;


    text = text + 1;
    int j = 0;
    while (*text) {
        int triggered = 0;
        if (*(text - 1) == ' ' && *text == ' ') {
            triggered = 1;
            int i = 0;
            while (*text) {
                *(text - 1) = *text;
                text++;
                i++;
            }
            *(text - 1) = *text;
            text = text - i;
        }
        if (!triggered) {
            text++;
            j++;
        }
    }
    if (*(text - 1) == ' ') {
        *(text - 1) = *(text);
    }
    text = text - 1 - j;

    if (*text == ' ') {
        int i = 0;
        while (*(text + 1)) {
            *(text) = *(text + 1);
            text++;
            i++;
        }
        *text = *(text + 1);
        text = text - i;
    }
    return text;
}