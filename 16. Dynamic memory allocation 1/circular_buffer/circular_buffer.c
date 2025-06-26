#include <stdio.h>
#include <stdlib.h>
#include "circular_buffer.h"
#include "tested_declarations.h"
#include "rdebug.h"

int circular_buffer_create(struct circular_buffer_t *cb, int N)
{
    if(cb == NULL || N <= 0)
        return 1;
    cb->ptr = malloc(N*sizeof(int));
    if (cb->ptr == NULL)
        return 2;
    cb->begin = 0;
    cb->end = 0;
    cb->capacity = N;
    cb->full = 0;
    return 0;
}

int circular_buffer_create_struct(struct circular_buffer_t **cb, int N)
{
    if(cb == NULL || N <= 0)
    {
        return 1;
    }
    *cb = malloc(sizeof(struct circular_buffer_t));
    if(*cb == NULL)
        return 2;
    if(circular_buffer_create(*cb, N) == 2)
    {
        free(*cb);
        return 2;
    }
    return 0;
}

void circular_buffer_destroy(struct circular_buffer_t *a)
{
    if(a == NULL || a->ptr == NULL)
        return;
    free(a->ptr);


}

void circular_buffer_destroy_struct(struct circular_buffer_t **a)
{
    if(a == NULL || *a == NULL || (*a)->ptr == NULL)
    {
        return;
    }
    circular_buffer_destroy(*a);
    free(*a);
}

int circular_buffer_push_back(struct circular_buffer_t *cb, int value)
{

    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0
       || cb->begin < 0 || cb->end < 0 || cb->begin > cb->capacity || cb->end > cb->capacity
       || (cb->full != 0 && cb->full != 1))
    {
        return 1;
    }

    *(cb->ptr + cb->end) = value;
    if(cb->end == cb->capacity - 1)
    {
        cb->end = 0;
        if(cb->full == 1)
            cb->begin = cb->end;
    }
    else
    {
        if(cb->end == cb-> begin && cb-> full == 1)
            cb->begin = cb->begin + 1;
        cb->end = cb->end + 1;
    }

    if(cb->end == cb-> begin)
        cb->full = 1;


    return 0;
}

int circular_buffer_pop_front(struct circular_buffer_t *cb, int *err_code)
{
    if(err_code != NULL)
        *err_code = 0;
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0
       || cb->begin < 0 || cb->end < 0 || cb->begin > cb->capacity ||
       cb->end > cb->capacity || (cb->full != 0 && cb->full != 1))
    {
        if(err_code != NULL)
            *err_code = 1;
        return 0;
    }

    if(cb->begin == cb->end && cb->full == 0)
    {
        if(err_code != NULL)
            *err_code = 2;
        return 0;
    }

    int number = *(cb ->ptr + cb->begin);
    cb->begin = cb->begin + 1;
    if (cb -> begin >= cb-> capacity)
    {
        cb-> begin = 0;
    }
    cb->full = 0;
    return number;
}

int circular_buffer_pop_back(struct circular_buffer_t *cb, int *err_code)
{
    if(err_code != NULL)
        *err_code = 0;
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0
       || cb->begin < 0 || cb->end < 0 || cb->begin > cb->capacity || cb->end > cb->capacity
       || (cb->full != 0 && cb->full != 1))
    {
        if(err_code != NULL)
            *err_code = 1;
        return 0;
    }

    if(cb->begin == cb->end && cb->full == 0)
    {
        if(err_code != NULL)
            *err_code = 2;
        return 0;
    }
    int number;
    if(cb->end == 0)
    {
        number = *(cb ->ptr+(cb->capacity-1));
        cb->end = cb->capacity-1;
    }
    else
    {
        number = *(cb ->ptr+(cb->end-1));
        cb->end = cb->end-1;
    }
    cb->full = 0;
    /*if(cb->end == cb->begin)
    {
        cb->end = 0;
        cb->begin = 0;
    }*/
    return number;
}

int circular_buffer_empty(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0
       || cb->begin < 0 || cb->end < 0 || cb->begin > cb->capacity || cb->end > cb->capacity
       || (cb->full != 0 && cb->full != 1))
        return -1;
    if(cb->begin == cb->end && cb-> full == 0)
        return 1;
    return 0;
}

int circular_buffer_full(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0
       || cb->begin < 0 || cb->end < 0 || cb->begin > cb->capacity || cb->end > cb->capacity
       || (cb->full != 0 && cb->full != 1))
        return -1;
    if(cb->begin == cb->end && cb-> full == 1)
        return 1;
    return 0;
}

void circular_buffer_display(const struct circular_buffer_t *cb)
{
    if(cb == NULL || cb->ptr == NULL || cb->capacity <= 0
       || cb->begin < 0 || cb->end < 0 || cb->begin > cb->capacity || cb->end > cb->capacity
       || (cb->full != 0 && cb->full != 1) || (cb->begin == cb->end && cb->full == 0))
        return;
    //int round = 1;
    for(int i = cb->begin;; i++)
    {
        if(i%cb->capacity == cb-> end && (i/cb->capacity) >= 1 && cb->full == 1)
        {
            break;
        }
        if(i%cb->capacity == cb-> end && cb->full != 1)
        {
            break;
        }
        printf("%d ", *(cb->ptr + (i%cb->capacity)));
    }
}

