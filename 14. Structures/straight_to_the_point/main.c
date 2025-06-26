#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct point_t {
    int x;
    int y;
};


struct point_t* set(struct point_t* p, int x, int y)
{
    if (p == NULL)
        return NULL;
    else
    {
        p->x = x;
        p->y = y;
    }
    return p;
}

struct point_t* read(struct point_t* p)
{
    if (p == NULL)
    {
        return NULL;
    }

    int x, y;
    printf("Podaj współrzędną x:");
    if(!scanf("%d", &x))
        return NULL;
    printf("Podaj współrzędną y:");
    if(!scanf("%d", &y))
        return NULL;
    if (set(p, x, y) == NULL)
        return NULL;

    return p;

}


void show(const struct point_t* p)
{
    if (p == NULL)
        return;
    else
    {
        printf("x = %d; y = %d\n", p->x, p->y);
    }
}

float distance(const struct point_t* p1, const struct point_t* p2, int *err_code)
{

    if(p1 == NULL || p2 == NULL || err_code == NULL)
    {
        if (err_code != NULL && (p1 == NULL || p2 == NULL))
        {
            *err_code = 1;
            return -1;
        }
        else if (err_code != NULL)
            *err_code = 0;
        else if (err_code == NULL && p1 == NULL && p2 == NULL)
            return -1;
    }
    else if (err_code != NULL)
        *err_code = 0;
    return (float)sqrt(((p1->x - p2->x)*(p1->x - p2->x)+(p1->y - p2->y)*(p1->y - p2->y)));
}

int main() {
    srand(time(NULL));
    struct point_t first, second;
    if (read(&first) == NULL) {
        printf("Incorrect input");
        return 1;
    }

    show(&first);
    int x = 1 + rand() % 100;
    int y = 1 + rand() % 100;
    if (set(&second, x, y) == NULL)
    {
        printf("Incorrect input");
        return 1;
    }
    show(&second);
    int err_code;
    float dist = distance(&first, &second, &err_code);
    if (dist == -1) {
        printf("Incorrect input");
        return 1;
    }
    printf("%.2f", dist);
    return 0;
}

