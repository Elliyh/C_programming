#include <stdio.h>
#include "sort.h"
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int bubble_sort_asc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int temp;
    int zamen = 0;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        zamen = 0;
        for (int j = 0; j < size - i-1; j++)
        {
            if (tab[j]>tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                zamen += 1;
            }
        }
        if (zamen != 0)
        {
            display_vector(tab, size);
            printf("\n");
        }
        if (zamen == 0)
        {
            break;
        }

    }
    return 0;
}


int bubble_sort_desc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int temp;
    int zamen = 0;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        zamen = 0;
        for (int j = 0; j < size - i-1; j++)
        {
            if (tab[j]<tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                zamen += 1;
            }
        }
        if (zamen != 0)
        {
            display_vector(tab, size);
            printf("\n");
        }
        if (zamen == 0)
        {
            break;
        }

    }
    return 0;
}


int bubble_sort(int tab[], int size, enum direction dir)
{
    if (size <= 0 || (dir != ASCENDING && dir != DESCENDING))
    {
        return 1;
    }
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    if (dir == ASCENDING)
    {
        bubble_sort_asc(tab, size);
    }
    else if (dir == DESCENDING)
    {
        bubble_sort_desc(tab, size);
    }
    display_vector(tab, size);
    printf("\n");
    return 0;
}
