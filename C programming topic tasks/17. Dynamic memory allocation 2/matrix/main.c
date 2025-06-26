#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


struct matrix_t{
    int **ptr;
    int width;
    int height;
};

void destroy_array_2d(int **ptr, int height)
{
    if(ptr == NULL || height <= 0)
        return;
    for(int i = 0; i < height; i++) {
        free(*(ptr+i));
    }
    free(ptr);
}

void matrix_destroy(struct matrix_t *m)
{
    if(m == NULL)
        return;
    if(m->ptr != NULL)
    {
        if(*(m->ptr) != NULL)
        {
            /*for(int g = 0; g <= m->height; g++)
            {
                free(*(m->ptr+g));
            }*/
            destroy_array_2d(m->ptr, m->height);
            m->height = 0;
            m->width = 0;
        }
    }
}

int matrix_create(struct matrix_t *m, int width, int height)
{
    if(width <= 0 || height <= 0 || m == NULL)
        return 1;

    int **rows = malloc(height * sizeof(int*));
    if (rows == NULL)
    {
        return 2;
    }
    int i;
    for(i = 0; i < height; i++)
    {
        *(rows+i) = malloc(sizeof(int) * width);
        if(*(rows+i) == NULL)
        {
            for(int g = i-1; g >= 0; g -- )
            {
                free(*(rows+g));
            }
            free(rows);
            return 2;
        }
    }
    m->height = height;
    m->width = width;
    m->ptr = rows;
    return 0;
}

int matrix_read(struct matrix_t *m)
{
    if(m == NULL || m->ptr == NULL || m->width <= 0 || m->height <= 0)
        return 1;
    int i, j;
    for(i = 0; i< m->height; i++)
    {
        for(j = 0; j < m->width; j++)
        {
            if(!scanf("%d", (*(m->ptr+i)+j))){
                return 2;
            }
        }
    }
    return 0;
}

void matrix_display(const struct matrix_t *m)
{
    if(m == NULL || m->ptr == NULL || m->width <= 0 || m->height <= 0) //*ptr == NULL
    {
        return;
    }
    int i, j;
    for(i = 0; i< m->height; i++)
    {
        for(j = 0; j < m->width; j++)
        {
            printf("%d ", *(*(m->ptr+i)+j));
        }
        printf("\n");
    }
}

int main() {
    struct matrix_t ukaz;
    printf("Podaj szerokość i wysokość:");
    int width, height;
    if(scanf("%d %d", &width, &height) != 2)
    {
        printf("incorrect input");
        return 1;
    }
    if(height<= 0 || width <= 0)
    {
        printf("incorrect input data");
        return 2;

    }
    int prov = matrix_create(&ukaz, width, height);
    if (prov == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj wartości:");
    prov = matrix_read(&ukaz);
    if(prov ==  2)
    {
        printf("incorrect input");
        matrix_destroy(&ukaz);
        return 1;
    }
    matrix_display(&ukaz);
    matrix_destroy(&ukaz);
    return 0;
}




