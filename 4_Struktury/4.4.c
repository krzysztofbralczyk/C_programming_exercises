#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct point_t* set(struct point_t* p, int x, int y);
void show(const struct point_t* p);
int save_point_b(const char *filename, const struct point_t* p);
int load_point_b(const char *filename, struct point_t* p);
int save_point_t(const char *filename, const struct point_t* p);
int load_point_t(const char *filename, struct point_t* p);

struct point_t{
    int x;
    int y;
};

int main(){

    struct point_t p1, *pt1;
    srand(time(NULL));
    pt1 = &p1;
    set(pt1, rand()%2001-1000, rand()%2001-1000);
    show(pt1);
    printf("Path to file: ");
    char path[31] = {'\0'};
    scanf("%30s",path);
    char* format = path + strlen(path) - 4;
    char answer = 'a';
    if(strcmp(format,".txt") == 0){

        if(save_point_t(path,pt1) != 0){
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
            int load_returned = load_point_t(path,pt1);
            if(load_returned == 3){
                printf("File corrupted");
                return 6;
            } else if(load_returned == 1 || load_returned == 2){
                printf("Couldn't open file");
                return 4;
            } else {
                show(pt1);
            }
        } else return 0;

    } else if(strcmp(format,".bin") == 0){
        if(save_point_b(path,pt1) != 0){
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
            int load_returned = load_point_b(path,pt1);
            if(load_returned == 3){
                printf("File corrupted");
                return 6;
            } else if(load_returned == 1 || load_returned == 2){
                printf("Couldn't open file");
                return 4;
            } else {
                show(pt1);
            }
        } else return 0;

    } else {
        printf("Unsupported file format");
        return 7;
    }
    return 0;
}


struct point_t* set(struct point_t* p, int x, int y){
    if(p == NULL) return NULL;

    p->x = x;
    p->y = y;
    return p;
}
void show(const struct point_t* p){
    if(p == NULL) return;

    printf("x = %d; y = %d\n",p->x,p->y);
}

int save_point_b(const char *filename, const struct point_t* p){
    if(filename == NULL || p == NULL) return 1;
    FILE* fp = fopen(filename,"wb");
    if(fp == NULL) return 2;
    if(!fwrite(p,sizeof(*p),1,fp)){
        fclose(fp);
        return 3;
    }
    fclose(fp);

    return 0;
}
int load_point_b(const char *filename, struct point_t* p){
    if(filename == NULL || p == NULL) return 1;
    FILE* fp = fopen(filename,"rb");
    if(fp == NULL) return 2;
    if(!fread(p,sizeof(*p),1,fp)){
        fclose(fp);
        return 3;
    }
    fclose(fp);

    return 0;
}
int save_point_t(const char *filename, const struct point_t* p){
    if(filename == NULL || p == NULL) return 1;
    
    FILE* fp = fopen(filename,"w");
    if(fp == NULL) return 2;
 
    if(fprintf(fp,"%d %d",p->x,p->y) < 0){
        fclose(fp);
        return 3;
    } 
    fclose(fp);
    return 0;
}
int load_point_t(const char *filename, struct point_t* p){
    if(filename == NULL || p == NULL) return 1;
    FILE* fp = fopen(filename,"r");
    if(fp == NULL) return 2;
    if(fscanf(fp,"%d %d",&(p->x),&(p->y))!=2){
        fclose(fp);
        return 3;
    }
    if( fgetc(fp) != EOF){
        fclose(fp);
        return 3;
    }
    fclose(fp);
    return 0;
}