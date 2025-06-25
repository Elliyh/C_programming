#include "vector_utils.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int read_vector_float(float *vec, int size, float stop_value)
{
    if (size <= 0 || vec == NULL)
    {
        return -1;
    }
    int i;
    for (i = 0; i < size; i++)
    {
        if (!scanf("%f", vec))
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

void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}



int sort(float * tab, int size)
{
    if (size < 1 || tab == NULL)
    {
        return 1;
    }
    int zamen = 0;
    if (size == 1)
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        zamen = 0;
        for (int j = 0; j < size - i-1; j++)
        {
            if (*(tab+j)>*(tab+j+1))
            {
                swap((tab+j), tab+j+1);
                zamen += 1;
            }
        }
        if (zamen == 0)
        {
            break;
        }

    }
    return 0;
}




int create_histogram(const float *vec, int size, int *out, int out_size)
{
    if (vec == NULL || out == NULL || size <= 0 || out_size <= 0)
        return 1;


    int i, j;


    for (i = 0; i < out_size; i++)
    {
        *(out+i) = 0;
    }


    for (i = 0; i < out_size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if ((float)i <= *(vec+j) && *(vec+j) < (float)i+1)
            {
                *(out+i) += 1;
            }
        }
    }

    return 0;
}
