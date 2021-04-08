#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
struct student_t
{
    char name[20];
    char surname[40];
    int index;
};
struct student_t* read(int *err_code);
void show(const struct student_t* p);
void destroy(struct student_t **s);
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
    if (*(text - 1) == ' '){
    *(text - 1) = *(text);
    }
    text = text - 1 - j;

    if(*text == ' '){
        int i = 0;
        while (*(text+1)) {
            *(text) = *(text+1);
            text++;
            i++;
        }
        *text = *(text+1);
        text = text - i;
    }
    return text;
}    

int main(){
    struct student_t* p = (struct student_t*)malloc(sizeof(struct student_t));
    if(p == NULL){
        printf("Failed to allocate memory");
        return 8;
    } else {
        free(p);
        printf("Podaj dane studenta w formacie \'imie, nazwisko, numer indeksu\':\n");
    }
    
    int error_code;
    struct student_t *sp = read(&error_code);
    
    if(sp == NULL){
        printf("Incorrect input");
        destroy(&sp);
        return error_code;
    }
    
    show(sp);
    destroy(&sp);


    return 0;
}

struct student_t* read(int *err_code){
    
    struct student_t* p = (struct student_t*)malloc(sizeof(struct student_t));

    if(p == NULL){
        if(err_code!= NULL) *err_code = 4;
        return NULL;
    }

    scanf("%20[^,^\n]",p->name);
    if(getchar() != ','){
        if(err_code!= NULL) *err_code = 1;
        free(p);
        return NULL;
    }
    strcpy(p->name,ltrim(p->name));

    scanf("%40[^,^\n]",p->surname);
    if(getchar() != ','){
        if(err_code!= NULL) *err_code = 2;
        free(p);
        return NULL;
    }
    strcpy(p->surname,ltrim(p->surname));

    char num = getchar();
    while(!isdigit(num) && num != '\n') num = getchar();
    if(num == '\n'){
        if(err_code!= NULL) *err_code = 3;
        free(p);
        return NULL;
    }

    p->index = 0;
    while(isdigit(num)){
        p->index = (p->index)*10 + (num - '0');
        num = getchar();
    }


    if(err_code!= NULL) *err_code = 0;

    return p;
}
void show(const struct student_t* p){
    if(p == NULL) return;
    printf("%s %s, %d",p->name,p->surname,p->index);
}
void destroy(struct student_t **s){
    if(s == NULL) return;
    else free(*s);
}