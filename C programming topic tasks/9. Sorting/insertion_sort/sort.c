#include <stdio.h>
#include "sort.h"
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int insertion_sort_asc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }
    int i, j, new;
    for (i = 1; i < size; i++)
    {
        new = tab[i];
        j = i - 1;

        while (j >= 0 && tab[j] > new)
        {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = new;
        display_vector(tab, size);
        printf("\n");
    }


    return 0;

}


int insertion_sort_desc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }

    int i, j, new;
    for (i = 1; i < size; i++)
    {
        new = tab[i];
        j = i - 1;
        while(new > tab[j] && j >= 0)
        {
            tab[j+1] = tab[j];
            j -= 1;
        }
        tab[j+1] = new;
        display_vector(tab, size);
        printf("\n");
    }

    return 0;
}


int insertion_sort(int tab[], int size, enum direction dir)
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
        insertion_sort_asc(tab, size);
    }
    else {
        insertion_sort_desc(tab, size);
    }
    display_vector(tab, size);
    printf("\n");
    return 0;
}
