#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"

struct matrix_t* matrix_create_struct(int width, int height)
{
    if(width <= 0 || height <= 0)
        return NULL;

    int **rows = malloc(height * sizeof(int*));
    if (rows == NULL)
    {
        return NULL;
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
            return NULL;
        }
    }
    struct matrix_t* ukaz = malloc(sizeof(struct matrix_t));
    if(ukaz == NULL)
    {
        for(int g = height-1; g >= 0; g -- )
        {
            free(*(rows+g));
        }
        free(rows);
        free(ukaz);
        return NULL;
    }
    ukaz->height = height;
    ukaz->width = width;
    ukaz->ptr = rows;
    return ukaz;
}

void matrix_destroy_struct(struct matrix_t **m)
{
    if(m == NULL || *m == NULL || (*m)->height <= 0)
        return;
    for(int i = 0; i < (*m)->height; i++) {
        free(*((*m)->ptr+i));
    }
    free((*m)->ptr);
    free(*m);
    *m = NULL;
}

struct matrix_t* matrix_transpose(const struct matrix_t *m)
{
    if(m == NULL || m->ptr == NULL || m->height <= 0 || m->width <= 0)
        return NULL;
    struct matrix_t* new_ukaz = matrix_create_struct(m->height, m->width);
    if(new_ukaz == NULL)
        return NULL;
    int i, j;
    for (i = 0; i < m->width; i++)
    {
        for(j = 0; j < m->height; j++)
        {
            *(*(new_ukaz->ptr+i)+j) = *(*(m->ptr+j)+i);
        }
    }
    return new_ukaz;
}

int matrix_save_b(const struct matrix_t *m, const char *filename)
{
    if(m == NULL || m->ptr == NULL || filename== NULL || m->width <= 0 || m->height <= 0)//((*(filename+ strlen(filename)-1) != 'n' && *(filename+ strlen(filename)-2) != 'i'&& *(filename+ strlen(filename)-3) != 'b' && *(filename+ strlen(filename)-4) != '.') && (*(filename+ strlen(filename)-1) != 't' && *(filename+ strlen(filename)-2) != 'x'&& *(filename+ strlen(filename)-3) != 't' && *(filename+ strlen(filename)-4) != ','))
        return 1;
    FILE *f = fopen(filename, "wb");
    if (f == NULL)
        return 2;
    if(fwrite(&(m->width), sizeof(int) , 1, f) != 1)
    {
        fclose(f);
        return 3;
    }
    if(fwrite(&(m->height), sizeof(int) , 1, f)!= 1)
    {
        fclose(f);
        return 3;
    }
    int i, j;
    for (i = 0; i < m->height; i++)
    {
        for(j = 0; j < m->width; j++)
        {
            if(fwrite((*(m->ptr+i)+j), sizeof(int) , 1, f) != 1)
            {
                fclose(f);
                return 3;
            }
        }
    }
    fclose(f);
    return 0;
}
int matrix_save_t(const struct matrix_t *m, const char *filename){
    if(m == NULL || m->ptr == NULL || filename== NULL || m->width <= 0 || m->height <= 0)
        return 1;
    FILE *f = fopen(filename, "w");
    if (f == NULL)
        return 2;
    if(fprintf(f, "%d %d\n", m->width, m->height) < 0)
    {
        fclose(f);
        return 3;
    }
    int i, j;
    for (i = 0; i < m->height; i++)
    {
        for(j = 0; j < m->width; j++)
        {
            if(fprintf(f, "%d ", *(*(m->ptr+i)+j)) < 0)
            {
                fclose(f);
                return 3;
            }
        }
        if(fprintf(f, "\n") < 0)
        {
            fclose(f);
            return 3;
        }
    }
    fclose(f);
    return 0;

}

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
            /*for(int g = 0; g < m->height; g++)
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


