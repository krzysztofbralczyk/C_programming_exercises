#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

struct point_t* set(struct point_t* p, int x, int y);
void show(const struct point_t* p);
struct point_t* read(struct point_t* p);
float distance(const struct point_t* p1, const struct point_t* p2, int *err_code);

struct point_t{
    int x;
    int y;
};

int main(){
    struct point_t p1, p2, *pt1, *pt2;
    int error_code;
    srand(time(NULL));
    pt1 = &p1;
    pt2 = &p2;
    if(read(pt1) == NULL) {
        printf("Incorrect input");
        return 1;
    }
    set(pt2, rand()%2001-1000, rand()%2001-1000);
    show(pt1);
    show(pt2);
    float result = distance(pt1,pt2,&error_code);
    printf("%.2f",result);
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

struct point_t* read(struct point_t* p){
    if(p == NULL) return NULL;

    printf("Podaj wspolrzedna x: ");
    int x;
    if(!scanf("%d",&x)) return NULL;

    printf("Podaj wspolrzedna y: ");
    int y;
    if(!scanf("%d",&y)) return NULL;

    set(p,x,y);
    return p;
}

float distance(const struct point_t* p1, const struct point_t* p2, int *err_code){
    if(p1 == NULL || p2 == NULL){
        if(err_code != NULL) *err_code = 1;
        return -1;
    }
    // printf("|%d|%d|%d|%d|",p1->x,p1->y,p2->x,p2->y);
    int x_dif = (p1->x) - (p2->x);
    // printf("|%d|",x_dif);
    int y_dif = (p1->y) - (p2->y);
    // printf("|%d|",y_dif);

    float result = sqrt(pow((float)(x_dif),2) + pow((float)(y_dif),2));
    if(err_code != NULL) *err_code = 0;
    return result;
}