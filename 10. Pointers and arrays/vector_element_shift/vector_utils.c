#include "vector_utils.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int read_vector(int *vec, int size, int stop_value)
{
    if (size <= 0 || vec == NULL)
    {
        return -1;
    }
    int i;
    for (i = 0; i < size; i++)
    {
        if (!scanf("%d", vec))
        {
            return -2;
        }
        if (*vec == stop_value)
        {
            break;
        }
        vec++;

    }
    return i;
}

void display_vector(const int* tab, int size)
{
    int i;
    for (i = 0; i < size; i++) // !!!!!!
    {
        printf("%d ", *(tab+i));
    }
}


int shift(int *array, int array_size, int positions_to_shift, enum direction dir)
{
    if(array == NULL || array_size <= 0 || (dir != ROTATE_RIGHT && dir != ROTATE_LEFT) || positions_to_shift < 0)
        return 1;
    else if (positions_to_shift == 0)
        return 0;

    int i, j;
    if (dir == ROTATE_RIGHT)
    {
        for(i = 0; i < positions_to_shift; i++)
        {
            for(j = array_size-1; j > 0; j--)
            {
                swap(array + j -1, array +j);
            }
        }
    }
    else
    {
        for(i = 0; i < positions_to_shift; i++)
        {
            for(j = 0; j < array_size - 1; j++)
            {

                swap(array + j , array + j + 1);
            }
        }
    }

    return 0;
}
