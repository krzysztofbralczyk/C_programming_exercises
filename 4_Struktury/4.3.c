#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct student_t* read(struct student_t* p, int *err_code);
struct student_t* set(struct student_t* student, const char * name,
                      const char * surname, int index,
                      const char * field, const char * faculty,
                      int year, int *err_code);


void display(const struct student_t* p);
void display_name(const struct student_t* student);
void display_surname(const struct student_t* student);
void display_index(const struct student_t* student);
void display_field(const struct student_t* student);
void display_faculty(const struct student_t* student);
void display_year(const struct student_t* student);

struct student_t
{
    char name[20];
    char surname[40];
    int index;
    char field[50];
    char faculty[80];
    int year;
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
    struct student_t student, *sp, student2, *sp2;
    sp = &student;
    sp2 = &student2;
    int error_code1,error_code2;
    printf("Podaj dane studenta w formacie \'imie, nazwisko, numer indeksu, kierunek, wydzial,rok studiow\':\n");

    if(read(sp,&error_code1) == NULL){
        printf("Incorrect input\n");
    } else {
        display(sp);
    }

    set(sp2,"Krzysztof","Bralczyk",228697,"Informatyka","Weeia",2020,&error_code2);
    display(sp2);
    if(error_code1 == 0){
        display_name(sp);
        display_surname(sp);
        display_index(sp);
        display_field(sp);
        display_faculty(sp);
        display_year(sp);
    }
    


    return error_code1;
}

struct student_t* read(struct student_t* p, int *err_code){
    if(p == NULL){
        if(err_code!= NULL) *err_code = 1;
        return NULL;
    }

    scanf("%20[^,^\n]",p->name);
    
    if(getchar() != ',' || strcmp(p->name," ")==0){
        if(err_code!= NULL) *err_code = 1;
        return NULL;
    }
    strcpy(p->name,ltrim(p->name));

    scanf("%40[^,^\n]",p->surname);

    if(getchar() != ',' || strcmp(p->surname," ")==0){
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

    if(num != ','){
        if(err_code!= NULL) *err_code = 3;
        return NULL;
    }

    scanf("%50[^,^\n]",p->field);
    
    if(getchar() != ',' || strcmp(p->field," ")==0){
        if(err_code!= NULL) *err_code = 4;
        return NULL;
    }
    strcpy(p->field,ltrim(p->field));

    scanf("%80[^,^\n]",p->faculty);
    
    if(getchar() != ',' || strcmp(p->faculty," ")==0){
        if(err_code!= NULL) *err_code = 5;
        return NULL;
    }
    strcpy(p->faculty,ltrim(p->faculty));

    num = getchar();
    while(!isdigit(num) && num != '\n') num = getchar();
    if(num == '\n'){
        if(err_code!= NULL) *err_code = 6;
        return NULL;
    }

    p->year = 0;
    while(isdigit(num)){
        p->year = (p->year)*10 + (num - '0');
        num = getchar();
    }


    if(err_code!= NULL) *err_code = 0;

    return p;
}

struct student_t* set(struct student_t* student, const char * name, const char * surname, int index, const char * field, const char * faculty, int year, int *err_code){
    if(student == NULL || name == NULL || surname == NULL || field == NULL || faculty == NULL || strlen(name)>19 || strlen(surname)>39 || strlen(field) > 49 || strlen(faculty)>79){
        if(err_code != NULL) *err_code = 1;
        return NULL;
    }

    strcpy(student->name,name);
    strcpy(student->surname,surname);
    student->index = index;
    strcpy(student->field,field);
    strcpy(student->faculty,faculty);
    student->year = year;
    if(err_code != NULL) *err_code = 0;
    return student;

}

//Jan Kowalski, index number: 112233, was a Sustainable Energy student at the Faculty of Biotechnology and Food Sciences in 2017.

void display(const struct student_t* p){
    if(p == NULL) return;
    if(tolower(*(p->field))=='a' || tolower(*(p->field))=='e' || tolower(*(p->field))=='i' || tolower(*(p->field))=='o' || tolower(*(p->field))=='u' || tolower(*(p->field))=='y'){
        printf("%s %s, index number: %d, was an %s student at the %s in %d.\n",p->name,p->surname,p->index,p->field,p->faculty,p->year);
    } else {
        printf("%s %s, index number: %d, was a %s student at the %s in %d.\n",p->name,p->surname,p->index,p->field,p->faculty,p->year);
    }
    
}
void display_name(const struct student_t* student){
    if(student == NULL) return;
    printf("Student name: %s\n",student->name);
}
void display_surname(const struct student_t* student){
    if(student == NULL) return;
    printf("Student surname: %s\n",student->surname);
}
void display_index(const struct student_t* student){
    if(student == NULL) return;
    printf("Index: %d\n",student->index);
}
void display_field(const struct student_t* student){
    if(student == NULL) return;
    printf("Field: %s\n",student->field);
}
void display_faculty(const struct student_t* student){
    if(student == NULL) return;
    printf("Faculty: %s\n",student->faculty);
}
void display_year(const struct student_t* student){
    if(student == NULL) return;
    printf("Year: %d\n",student->year);
}

 