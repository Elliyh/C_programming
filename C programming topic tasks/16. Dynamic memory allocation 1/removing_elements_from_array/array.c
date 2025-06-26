#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int array_create(struct array_t *a, int N)
{
    if(N <= 0 || a == NULL)
        return 1;
    int* array = malloc(N * sizeof(int));
    if(array == NULL)
        return 2;
    a->ptr = array;
    a->size = 0;
    a->capacity = N;
    return 0;
}

int array_push_back(struct array_t *a, int value)
{
    if(a == NULL || a->capacity <= 0 || a->size < 0 || a->ptr == NULL || a->capacity < a->size)
    {
        return 1;
    }
    static int i = 0;
    if(a->size  == 0 && i != 0)
        i = 0;
    if(i >= (a->capacity))
        return 2;
    *((a->ptr)+i) = value;
    a->size = (a->size)+1;
    i++;
    return 0;
}

void array_display(const struct array_t *a)
{
    if(a == NULL || a->capacity <= 0 || a->size <= 0 || a->ptr == NULL || a->capacity < a->size)
    {
        return;
    }
    /*if(a->size == 0)
    {
        printf("Buffer is empty");
        return;
    }*/
    for(int i = 0; i < a->size; i++)
    {
        printf("%d ", *((a->ptr)+i));
    }
}

void array_destroy(struct array_t *a)
{
    if(a == NULL || a->capacity <= 0 || a->size < 0 || a->ptr == NULL)
    {
        return;
    }
    free(a->ptr);
    a->size = 0;
    a->capacity = 0;
}

int array_create_struct(struct array_t **a, int N)
{
      if(N <= 0 || a == NULL)
          return 1;

      *a = malloc(sizeof(struct array_t));
      if(*a == NULL)
          return 2;
      (*a)->ptr = malloc(N * sizeof(int));
      if((*a)->ptr == NULL)
      {
          free(*a);
          return 2;
      }

     (*a)->size = 0;
     (*a)->capacity = N;
     return 0;
}


int array_remove_item(struct array_t *a, int value)
{
    if(a == NULL || a->ptr == NULL || a->size < 0 || a->capacity <= 0 || a->size > a->capacity)
        return -1;
    int size = a->size, i, j, count = 0;
    for(i = size-1; i >= 0; i--)
    {
        if(*((a->ptr)+i) == value)
        {
            for(j = i; j < size-1; j++)
            {
                *((a->ptr)+j) = *((a->ptr)+j+1);
            }
            a->size = a->size - 1;
            count++;
        }
    }
    return count;
}

void array_destroy_struct(struct array_t **a)
{
    if(a == NULL || *a == NULL || (*a)->ptr == NULL)
        return;
    free((*a)->ptr);
    free(*a);
}


