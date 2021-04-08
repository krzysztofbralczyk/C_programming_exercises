#include <stdio.h>
#include <math.h>

struct point_t
{
    int x;
    int y;
};

struct rectangle_t
{
    struct point_t p;
    int width;
    int height;
};

struct circle_t
{
    struct point_t c;
    float r;
};

struct triangle_t
{
    struct point_t p1;
    struct point_t p2;
    struct point_t p3;
};

enum figure_types {
    TRIANGLE = 1,
    RECTANGLE,
    CIRCLE
};

struct figure_t {
    union
    {
        struct rectangle_t rect;
        struct triangle_t triangle;
        struct circle_t circ;
    };
    enum figure_types type;
};

float area_triangle(const struct triangle_t* t) {
    if (t == NULL || (t->p1.x == t->p2.x && t->p1.y == t->p2.y) || (t->p2.x == t->p3.x && t->p2.y == t->p3.y) || (t->p1.x == t->p3.x && t->p1.y == t->p3.y) || (t->p1.x == t->p2.x && t->p1.x == t->p3.x) || (t->p1.y == t->p2.y && t->p1.y == t->p3.y)) return -1;
    float first = (t->p1.x)*(t->p2.y - t->p3.y);

    float second = (t->p2.x)*(t->p3.y - t->p1.y);

    float third = (t->p3.x)*(t->p1.y - t->p2.y);

    double temp = (double)first + (double)second + (double)third;

    return 1.0 / 2 * fabs(temp);
}
float area_rectangle(const struct rectangle_t* r) {
    if (r == NULL || r->width <= 0 || r->height <= 0) return -1;
    return (float)(r->height * r->width);
}
float area_circle(const struct circle_t* c) {
    if (c == NULL || c->r <= 0) return -1;
    return 3.14159265 * pow(c->r, 2);
}
float area_figure(const struct figure_t* f) {
    if (f == NULL || f->type < 1 || f->type > 3) return -1;
    float result = 0;
    if (f->type == RECTANGLE) result = area_rectangle(&(f->rect));
    if (f->type == TRIANGLE) result = area_triangle(&(f->triangle));
    if (f->type == CIRCLE) result = area_circle(&(f->circ));
    return result;
}

void display_rectangle(const struct rectangle_t* rect) {
    if (rect == NULL) return;
    printf("Rectangle (%d, %d), width = %d, height = %d", rect->p.x, rect->p.y, rect->width, rect->height);
}
void display_triangle(const struct triangle_t* t) {
    if (t == NULL || (t->p1.x == t->p2.x && t->p1.y == t->p2.y) || (t->p2.x == t->p3.x && t->p2.y == t->p3.y) || (t->p1.x == t->p3.x && t->p1.y == t->p3.y) || (t->p1.x == t->p2.x && t->p1.x == t->p3.x) || (t->p1.y == t->p2.y && t->p1.y == t->p3.y)) return;
    printf("Triangle p1(%d, %d), p2(%d, %d), p3(%d, %d)", t->p1.x, t->p1.y, t->p2.x, t->p2.y, t->p3.x, t->p3.y);
}
void display_circle(const struct circle_t* circ) {
    if (circ == NULL) return;
    printf("Circle (%d, %d), radius = %f", circ->c.x, circ->c.y, circ->r);
}
void display_figure(struct figure_t* f) {
    if (f == NULL) return;
    if (f->type == RECTANGLE) display_rectangle(&(f->rect));
    if (f->type == TRIANGLE) display_triangle(&(f->triangle));
    if (f->type == CIRCLE) display_circle(&(f->circ));
}

// int bubble_sort(int tab[], int size){
//     if(size < 1) return 1;
//     int not_sorted = 1;
//     while(not_sorted){
//         not_sorted = 0;
//         for(int i = 0; i < size-1; i++){
//             if(tab[i+1] < tab[i]){
//                 int temp = tab[i];
//                 tab[i] = tab[i+1];
//                 tab[i+1] = temp;
//                 not_sorted = 1;
//             }
//         }
//         display_vector(tab,size);
//     }
//     return 0;
// }
int sort_by_area(struct figure_t** figures, int size) {
    if (figures == NULL || size <= 0) return 1;
    int not_sorted = 1;
    while (not_sorted) {
        not_sorted = 0;
        for (int i = 0; i < size - 1; i++) {
            if (area_figure(*(figures + i + 1)) == -1 || area_figure(*(figures + i)) == -1) return 1;
            if (area_figure(*(figures + i + 1)) > area_figure(*(figures + i))) {
                struct figure_t* temp;
                temp = *(figures + i + 1);
                *(figures + i + 1) = *(figures + i);
                *(figures + i) = temp;
                not_sorted = 1;
            }
        }
    }
    return 0;
}


int main() {

    int type, counter = 0;
    struct figure_t figures[50];
    struct figure_t* pfigures[50];
    for(int i = 0; i < 50; i++){
      *(pfigures + i) = figures+i;
    }

    while (counter < 50) {

        printf("Enter figure's type: ");

        if (!scanf("%d", &type)) {
            printf("Incorrect input");
            return 1;
        }

        if (type > 3 || type < 0) {
            printf("Incorrect input data");
            return 2;
        }

        if (type == 0) break;
        if (type == TRIANGLE) {
            printf("Enter vertices' coordinates of a triangle (x1 y1 x2 y2 x3 y3): ");
            int num1, num2, num3, num4, num5, num6;
            if (scanf("%d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6) != 6) {
                printf("Incorrect input");
                return 1;
            }

            (*(figures + counter)).triangle.p1.x = num1;
            (*(figures + counter)).triangle.p1.y = num2;
            (*(figures + counter)).triangle.p2.x = num3;
            (*(figures + counter)).triangle.p2.y = num4;
            (*(figures + counter)).triangle.p3.x = num5;
            (*(figures + counter)).triangle.p3.y = num6;
            (*(figures + counter)).type = TRIANGLE;
        }
        if (type == RECTANGLE) {
            printf("Enter coordinates of a rectangle along with its dimensions (x y width height): ");
            int num1, num2, num3, num4;
            if (scanf("%d %d %d %d", &num1, &num2, &num3, &num4) != 4) {
                printf("Incorrect input");
                return 1;
            }
            (*(figures + counter)).rect.p.x = num1;
            (*(figures + counter)).rect.p.y = num2;
            (*(figures + counter)).rect.width = num3;
            (*(figures + counter)).rect.height = num4;
            (*(figures + counter)).type = RECTANGLE;
        }
        if (type == CIRCLE) {
            printf("Enter coordinates and radius of a circle: ");
            int num1, num2;
            float num3;
            if (scanf("%d %d %f",&num1,&num2,&num3) != 3) {
                printf("Incorrect input");
                return 1;
            }
            (*(figures + counter)).circ.c.x = num1;
            (*(figures + counter)).circ.c.y = num2;
            (*(figures + counter)).circ.r = num3;
            (*(figures + counter)).type = CIRCLE;
        }

        counter++;
    }

    if (sort_by_area(pfigures, counter)) {
        printf("Incorrect input data");
        return 2;
    }

    for (int i = 0; i < counter; i++) {
        display_figure(*(pfigures + i));
        printf("\n");
    }

    return 0;
}