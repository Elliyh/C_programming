
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

enum figure_types
{
    TRIANGLE = 1,
    RECTANGLE,
    CIRCLE
};

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

struct figure_t
{
    union {
        struct rectangle_t rect;
        struct triangle_t triangle;
        struct circle_t circ;
    };
    enum figure_types type;
};

float area_triangle(const struct triangle_t *t)
{
    if(t == NULL)
        return -1;
    float p1_p2 = sqrt(pow(t->p1.x - t->p2.x, 2)+pow(t->p1.y - t->p2.y, 2));
    float p2_p3 = sqrt(pow(t->p2.x - t->p3.x, 2)+pow(t->p2.y - t->p3.y, 2));
    float p3_p1 = sqrt(pow(t->p3.x - t->p1.x, 2)+pow(t->p3.y - t->p1.y, 2));
    if(p1_p2 >= p2_p3+p3_p1 || p2_p3 >= p1_p2+p3_p1 || p3_p1 >= p2_p3+p1_p2)
        return -1;
    float p = (p1_p2 + p2_p3 + p3_p1)/2;
    return sqrt(p*(p-p1_p2)*(p-p2_p3)*(p-p3_p1));
}
float area_rectangle(const struct rectangle_t *r)
{
    if(r == NULL)
        return -1;
    if(r->height <= 0 || r ->width <= 0)
        return -1;
    return r->height * r -> width;
}
float area_circle(const struct circle_t *c)
{
    if (c == NULL)
        return -1;
    if(c->r <= 0)
        return -1;
    return M_PI * pow(c->r, 2);
}
float area_figure(const struct figure_t *f)
{
    if(f == NULL)
        return -1;
    if(f->type == TRIANGLE)
    {
        return area_triangle((struct triangle_t*)(&f->triangle));
    }
    else if(f->type == RECTANGLE)
    {
        return area_rectangle((struct rectangle_t*)(&f->rect));
    }
    else if(f->type == CIRCLE)
    {
        return area_circle((struct circle_t*)(&f->circ));
    }
    else{
        return -1;
    }

}

void display_rectangle(const struct rectangle_t *rect)
{
    if(rect == NULL)
        return;
    printf("Rectangle (%d, %d), width = %d, height = %d\n", rect->p.x, rect->p.y, rect->width, rect->height);
}
void display_triangle(const struct triangle_t *t)
{
    if(t == NULL)
        return;
    printf("Triangle p1(%d, %d), p2(%d, %d), p3(%d, %d)\n", t->p1.x, t->p1.y, t->p2.x, t->p2.y, t->p3.x, t->p3.y);
}
void display_circle(const struct circle_t *circ)
{
    if(circ == NULL)
        return;
    printf("Circle (%d, %d), radius = %.6f\n", circ->c.x, circ->c.y, circ->r);
}
void display_figure(struct figure_t *f)
{
    if(f == NULL)
        return;
    if(f->type == TRIANGLE)
    {
        display_triangle((struct triangle_t*)(&f->triangle));
    }
    else if(f->type == RECTANGLE)
    {
        display_rectangle((struct rectangle_t*)(&f->rect));
    }
    else if(f->type == CIRCLE)
    {
        display_circle((struct circle_t*)(&f->circ));
    }
    else{
        return;
    }
}

int sort_by_area(struct figure_t **figures, int size)
{
    if(figures == NULL || size <= 0)
    {
        return 1;
    }
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(area_figure(*(figures+j)) == -1 || area_figure(*(figures+j+1)) == -1)
            {
                return 1;
            }
            if(area_figure(*(figures+j)) < area_figure(*(figures+j+1)))
            {
                struct figure_t* temp = *(figures+j);
                *(figures+j) = *(figures+j+1);
                *(figures+j+1) = temp;
            }
        }
    }
    return 0;
}


int main() {
    struct figure_t* my_figures[50];
    int i;
    struct figure_t* adres = calloc(50, sizeof(struct figure_t));
    for(i = 0; i < 50; i++)
    {
        int types = 0;
        printf("Enter figure's type: ");
        if(!scanf("%d", &types))
        {
            printf("Incorrect input");
            free(adres);
            return 1;
        }
        if(types == 0)
        {
            break;
        }
        //struct figure_t* adres = calloc(50, sizeof(struct figure_t));
        switch (types)
        {
            case 1:
                printf("Enter vertices' coordinates of a triangle (x1 y1 x2 y2 x3 y3): ");
                (adres+i)->type = 1;
                if(scanf("%d %d %d %d %d %d", &(adres+i)->triangle.p1.x,
                         &(adres+i)->triangle.p1.y, &(adres+i)->triangle.p2.x,
                         &(adres+i)->triangle.p2.y, &(adres+i)->triangle.p3.x, &(adres+i)->triangle.p3.y)!= 6)
                {
                    printf("Incorrect input");
                    free(adres);
                    return 1;
                }
                *(my_figures + i) = (adres+i);
                //free(adres);
                break;
            case 2:
                printf("Enter coordinates of a rectangle along with its dimensions (x y width height): ");
                (adres+i)->type = 2;
                if(scanf("%d %d %d %d", &(adres+i)->rect.p.x, &(adres+i)->rect.p.y, &(adres+i)->rect.width,&(adres+i)->rect.height) != 4)
                {
                    printf("Incorrect input");
                    free(adres);
                    return 1;
                }
                *(my_figures + i) = (adres+i);
                //free(adres);
                break;
            case 3:
                printf("Enter coordinates and radius of a circle: ");
                (adres+i)->type = 3;
                if(scanf("%d %d %f", &(adres+i)->circ.c.x, &(adres+i)->circ.c.y, &(adres+i)->circ.r) != 3)
                {
                    printf("Incorrect input");
                    free(adres);
                    return 1;
                }
                *(my_figures + i) = (adres+i);
                //free(adres);
                break;
            default:
                printf("Incorrect input data");
                free(adres);
                return 2;

        }
    }
    if(sort_by_area( my_figures, i) == 1)
    {
        printf("Incorrect input data");
        free(adres);
        return 2;
    }
    for(int j = 0; j < i; j++)
    {
        display_figure(*(my_figures+j));
    }
    free(adres);
    return 0;
}

/*
1
15 -17 -6 34 35 43
1
19 34 -33 9 11 17
3
3 5 15.407781
2
0 -8 35 14
2
2 -9 31 37
0
 */
