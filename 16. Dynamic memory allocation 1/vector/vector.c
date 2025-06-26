#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "tested_declarations.h"
#include "rdebug.h"

int vector_create_struct(struct vector_t **a, int N)
{
    if(a == NULL || N <= 0)
        return 1;
    *a = malloc(sizeof(struct vector_t));
    if(*a == NULL)
        return 2;
    vector_create(*a, N);
    if((*a) -> ptr == NULL)
    {
        free(*a);
        return 2;
    }
    return 0;
}

void vector_destroy_struct(struct vector_t **a)
{
    if(a == NULL || *a == NULL)
        return;

    free((*a)->ptr);
    free(*a);
    

}

int vector_create(struct vector_t *a, int N)
{
    if(a == NULL || N <= 0)
        return 1;
    a->ptr = malloc(N * sizeof(int));
    if(a->ptr == NULL)
        return 2;
    a->size = 0;
    a->capacity = N;
    return 0;

}
void vector_destroy(struct vector_t *a)
{
    if(a == NULL)
        return;

    free(a->ptr);
}

void vector_display(const struct vector_t *a)
{
    if(a == NULL || a->ptr == NULL || a->capacity <= 0 || a->size < 0 || a->size > a->capacity)
    {
        return;
    }
    for(int i = 0; i < a->size; i++)
    {
        printf("%d ", *(a->ptr+i));
    }
}

int vector_push_back(struct vector_t *a, int value)
{
    if(a == NULL || a->ptr == NULL || a->capacity <= 0 || a->size < 0 || a->size > a->capacity)
    {
        return 1;
    }

    if(a->size == a->capacity)
    {
        int *new_tab = realloc(a->ptr, (a->capacity*2)*sizeof(int));
        if(new_tab == NULL)
            return 2;
        a -> ptr = new_tab;
        a->capacity = a->capacity * 2;
    }
    *(a->ptr+a->size) = value;
    a->size = a->size + 1;
    return 0;


}
int vector_erase(struct vector_t *a, int value)
{
    if(a == NULL || a->ptr == NULL || a->capacity <= 0 || a->size < 0 || a->size > a->capacity)
    {
        return -1;
    }
    int delete = 0, i, j;
    for(i = a->size - 1; i >= 0; i--)
    {
        if(*(a->ptr+i) == value)
        {
            for(j = i; j < a->size-1-delete; j++)
            {
                *(a->ptr+j) = *(a->ptr+j+1);
            }
            delete++;
        }

    }
    a->size = a->size - delete;
    if (a->capacity >= 2 && a->size < (int)(a->capacity/4))
    {
        a->ptr = realloc(a->ptr, (int) (a->capacity / 2)*sizeof(int));
        if(a->ptr == NULL)
            return -1;
        a->capacity = (int) (a->capacity / 2);
    }
    return delete;
}


