#include "vector_utils.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

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


