#include <stdio.h>
#include <string.h>
#include "image_utils.h"
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"



int image_draw_rectangle(struct image_t *img, const struct rectangle_t *rect, int value)
{
    if(img == NULL || img -> ptr == NULL || rect == NULL || img -> width <= 0 || img->height <= 0
    || strcmp(img->type, "P2")!= 0 || value <0 || value > 255 || rect -> width <= 0 || rect->height <= 0
    || rect->p.x < 0 || rect->p.y < 0 || rect->height + rect->p.y > img->height ||
            rect->width + rect->p.x > img->width)
    {
        return 1;
    }
    int i, j = rect->p.x;
    for(i = rect->p.y; i < rect->p.y + rect->height; i++)
    {
        *(*(img->ptr+i)+j) = value;
    }
    i--;
    for(; j < rect->p.x + rect->width; j++)
    {
        *(*(img->ptr+i)+j) = value;
    }
    j--;
    for(; i >= rect->p.y; i--)
    {
        *(*(img->ptr+i)+j) = value;
    }
    i++;
    for(; j >= rect->p.x; j--)
    {
        *(*(img->ptr+i)+j) = value;
    }
    return 0;
}

void destroy_image(struct image_t **m) {
    if (m == NULL || *m == NULL)return;
    for (int i = 0; i < (*m)->height; i++) {
        if (*((*m)->ptr + i) != NULL) {
            free(*((*m)->ptr + i));
        }
    }
    if ((*m)->ptr != NULL) {
        free((*m)->ptr);
    }
    free(*m);
    *m = NULL;
}



struct image_t* load_image_t(const char *filename, int *err_code)
{
    if(err_code != NULL)
        *err_code = 0;
    if(filename == NULL || !*filename){
        if(err_code != NULL)
            *err_code = 1;
        return NULL;
    }
    FILE *f = fopen(filename, "r");
    if(f == NULL)
    {
        if(err_code != NULL)
            *err_code = 2;
        return NULL;
    }

    struct image_t * obraz = calloc(1, sizeof(struct image_t));
    if(obraz == NULL)
    {
        if(err_code != NULL)
            *err_code = 4;
        fclose(f);
        return NULL;
    }
    if(fscanf(f, "%2s", obraz->type) == EOF || (*(obraz->type) != 'P' && *(obraz->type+1) != '2'))
    {
        if(err_code != NULL)
            *err_code = 3;
        fclose(f);
        free(obraz);
        return NULL;
    }
    if(strcmp(obraz->type, "P2") != 0)
    {
        if(err_code != NULL)
            *err_code = 3;
        fclose(f);
        free(obraz);
        return NULL;
    }
    if(fscanf(f, "%d %d", &(obraz->width), &(obraz->height)) != 2 ||  obraz->width <= 0 || obraz->height <= 0)
    {
        if(err_code != NULL)
            *err_code = 3;
        fclose(f);
        free(obraz);
        return NULL;
    }
    int color;
    if(fscanf(f, "%d", &color) != 1 || color > 255 || color < 0)
    {
        if(err_code != NULL)
            *err_code = 3;
        fclose(f);
        free(obraz);
        return NULL;
    }
    obraz->ptr = calloc(obraz->height, sizeof(int*));
    if(obraz->ptr == NULL)
    {
        if(err_code != NULL)
            *err_code = 4;
        free(obraz);
        fclose(f);
        return NULL;
    }
    int i, j;
    for(i = 0; i < obraz->height; i++)
    {
        *(obraz->ptr+i) = calloc(obraz->width, sizeof(int));
        if(*(obraz->ptr+i) == NULL)
        {
            int g = i-1;
            while(g>=0)
            {
                free(*(obraz->ptr+g));
                g--;
            }
            if(err_code != NULL)
                *err_code = 4;
            free(obraz->ptr);
            free(obraz);
            fclose(f);
            return NULL;
        }
    }
    for(i = 0; i < obraz->height; i++)
    {
        for(j = 0; j < obraz->width; j++)
        {
            if(fscanf(f, "%d", (*(obraz->ptr+i)+j)) != 1 || *(*(obraz->ptr+i)+j) < 0 || *(*(obraz->ptr+i)+j) > 255)
            {
                destroy_image(&obraz);
                if(err_code != NULL)
                    *err_code = 3;
                fclose(f);
                free(obraz);
                return NULL;
            }
        }
    }
    fclose(f);
    return obraz;
}



int save_image_t(const char * filename, const struct image_t *m1)
{
    if(filename == NULL || m1 == NULL || m1->ptr == NULL || m1->height <= 0 || m1->width <= 0 )
    {
        return 1;
    }
    FILE *f = fopen(filename, "w");
    if(f == NULL)
    {
        return 2;
    }
    if(fprintf(f, "%2s\n", m1->type) < 0)
    {
        fclose(f);
        return 3;
    }
    if(fprintf(f, "%d %d\n", m1->width, m1->height) < 0)
    {
        fclose(f);
        return 3;
    }
    if(fprintf(f, "255\n") < 0)
    {
        fclose(f);
        return 3;
    }
    int i, j;
    for(i = 0; i < m1->height; i ++)
    {
        for(j = 0; j < m1->width; j++)
        {
            if(fprintf(f, "%d", *(*(m1->ptr+i)+j)) < 0){
                fclose(f);
                return 3;
            }
            if(j+1 != m1->width)
            {
                if(fprintf(f, " " ) < 0 )
                {
                    fclose(f);
                    return 3;
                }
            }
        }
        if(fprintf(f, "\n" ) < 0)
        {
            fclose(f);
            return 3;
        }
    }
    fclose(f);
    return 0;
}


const int* image_get_pixel(const struct image_t *img, int x, int y)
{
    if(img == NULL || img->ptr == NULL ||  x < 0 || y < 0 || x >=img->width || y>= img->height)
    {
        return NULL;
    }
    return (*(img->ptr+y)+x);
}
int* image_set_pixel(struct image_t *img, int x, int y)
{
    if(img == NULL || img->ptr == NULL ||  x < 0 || y < 0 || x >= img->width || y >= img->height)
    {
        return NULL;
    }
    return (*(img->ptr+y)+x);
}

int draw_image(struct image_t *img, const struct image_t *src, int destx, int desty)
{
    if(img == NULL || img->ptr == NULL ||
       src == NULL || src -> ptr == NULL ||
       img->height <= 0 || src->height <= 0 ||
       src->width <= 0 || destx < 0 || desty < 0 || src->height + desty > img->height
       || src->width + destx > img->width)
    {
        return 1;
    }
    int i, j;
    for(i = desty; i < desty+src->height; i++)
    {
        for(j = destx; j < destx+src->width; j++)
        {
            *(*(img->ptr+i)+j) = *(*(src->ptr+i-desty)+j-destx);
        }
    }
    return 0;
}

