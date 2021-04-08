#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct student_t* read(struct student_t* p, int *err_code);

void display(const struct student_t* p);

int save_student_b(const char *filename, const struct student_t* s);
int load_student_b(const char *filename, struct student_t* s);
int save_student_t(const char *filename, const struct student_t* s);
int load_student_t(const char *filename, struct student_t* s);
void display_name(const struct student_t* student);
void display_surname(const struct student_t* student);
void display_index(const struct student_t* student);
void display_field(const struct student_t* student);
void display_faculty(const struct student_t* student);
void display_year(const struct student_t* student);
struct student_t* set(struct student_t* student, const char * name,
                      const char * surname, int index,
                      const char * field, const char * faculty,
                      int year, int *err_code);

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
    struct student_t student, *sp;
    sp = &student;
    int error_code1;

    printf("Podaj dane studenta w formacie \'imie, nazwisko, numer indeksu, kierunek, wydzial,rok studiow\':\n");
    if(read(sp,&error_code1) == NULL){
        printf("Incorrect input\n");
        return error_code1;
    } else {
        display(sp);
    }

    printf("Path to file: ");
    char path[31] = {'\0'};
    scanf("%30s",path);
    char* format = path + strlen(path) - 4;
    char answer = 'a';
    if(strcmp(format,".txt") == 0){

        if(save_student_t(path,sp) != 0){
            printf("Couldn't create file");
            return 5;
        }
        printf("File saved\nDo you want to read the file (Y/N)?");
        while(getchar() != '\n');
        scanf("%c",&answer);
        if(tolower(answer) != 'y' && tolower(answer) != 'n'){
            printf("Incorrect input");
            return 1;
        } else if(tolower(answer) == 'y'){
            int load_returned = load_student_t(path,sp);
            if(load_returned == 3){
                printf("File corrupted");
                return 6;
            } else if(load_returned == 1 || load_returned == 2){
                printf("Couldn't open file");
                return 4;
            } else {
                display(sp);
            }
        } else return 0;

    } else if(strcmp(format,".bin") == 0){
        if(save_student_b(path,sp) != 0){
            printf("Couldn't create file");
            return 5;
        }
        printf("File saved\nDo you want to read the file (Y/N)?");
        while(getchar() != '\n');
        scanf("%c",&answer);
        if(tolower(answer) != 'y' && tolower(answer) != 'n'){
            printf("Incorrect input");
            return 1;
        } else if(tolower(answer) == 'y'){
            int load_returned = load_student_b(path,sp);
            if(load_returned == 3){
                printf("File corrupted");
                return 6;
            } else if(load_returned == 1 || load_returned == 2){
                printf("Couldn't open file");
                return 4;
            } else {
                display(sp);
            }
        } else return 0;

    } else {
        printf("Unsupported file format");
        return 7;
    }
    return 0;

    


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


void display(const struct student_t* p){
    if(p == NULL) return;
    if(tolower(*(p->field))=='a' || tolower(*(p->field))=='e' || tolower(*(p->field))=='i' || tolower(*(p->field))=='o' || tolower(*(p->field))=='u' || tolower(*(p->field))=='y'){
        printf("%s %s, index number: %d, was an %s student at the %s in %d.\n",p->name,p->surname,p->index,p->field,p->faculty,p->year);
    } else {
        printf("%s %s, index number: %d, was a %s student at the %s in %d.\n",p->name,p->surname,p->index,p->field,p->faculty,p->year);
    }
    
}

int save_student_b(const char *filename, const struct student_t* s){
    if(filename == NULL || s == NULL) return 1;
    FILE* fp = fopen(filename,"wb");
    if(fp == NULL) return 2;
    if(!fwrite(s,sizeof(*s),1,fp)){
        fclose(fp);
        return 3;
    }
    fclose(fp);

    return 0;
}
int load_student_b(const char *filename, struct student_t* s){
    if(filename == NULL || s == NULL) return 1;
    FILE* fp = fopen(filename,"rb");
    if(fp == NULL) return 2;
    if(!fread(s,sizeof(*s),1,fp)){
        fclose(fp);
        return 3;
    }
    fclose(fp);

    return 0;
}
int save_student_t(const char *filename, const struct student_t* s){
    if(filename == NULL || s == NULL) return 1;
    FILE* fp = fopen(filename,"w");
    if(fp == NULL) return 2;
    if(fprintf(fp,"%s, %s, %d, %s, %s, %d",s->name,s->surname,s->index,s->field,s->faculty,s->year) < 0){
        fclose(fp);
        return 3;
    } 
    fclose(fp);
    return 0;
}
int load_student_t(const char *filename, struct student_t* s){
    if(filename == NULL || s == NULL) return 1;
    FILE* fp = fopen(filename,"r");
    if(fp == NULL) return 2;
    if(fscanf(fp,"%[^,], %[^,], %d, %[^,], %[^,], %d",s->name,s->surname,&(s->index),s->field,s->faculty,&(s->year))!=6){
        fclose(fp);
        return 3;
    }
    if( fgetc(fp) != EOF){
        // printf("Got triggered!");
        fclose(fp);
        return 3;
    }
    fclose(fp);
    return 0;
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
