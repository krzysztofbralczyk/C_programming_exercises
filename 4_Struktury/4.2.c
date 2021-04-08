#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct student_t* read(struct student_t* p, int *err_code);
void show(const struct student_t* p);

struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

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
    struct student_t student, *sp;
    sp = &student;
    int error_code;
    printf("Podaj dane studenta w formacie \'imie, nazwisko, numer indeksu\':\n");

    if(read(sp,&error_code) == NULL){
        printf("Incorrect input");
        // printf("Error code is %d",error_code);
        return error_code;
    }
    
    show(sp);


    return 0;
}

struct student_t* read(struct student_t* p, int *err_code){
    if(p == NULL){
        if(err_code!= NULL) *err_code = 1;
        return NULL;
    }

    scanf("%20[^,^\n]",p->name);
    if(getchar() != ','){
        if(err_code!= NULL) *err_code = 1;
        return NULL;
    }
    strcpy(p->name,ltrim(p->name));

    scanf("%40[^,^\n]",p->surname);
    if(getchar() != ','){
        if(err_code!= NULL) *err_code = 2;
        return NULL;
    }
    strcpy(p->surname,ltrim(p->surname));

    char num = getchar();
    while(!isdigit(num) && num != '\n') num = getchar();
    if(num == '\n'){
        if(err_code!= NULL) *err_code = 3;
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

 