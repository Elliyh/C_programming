#include <stdio.h>
#include "sort.h"
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

int selection_sort_asc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int temp;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }


    //int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (tab[j] < tab[min_index]) {
                min_index = j;
            }
        }


        if (min_index != i) {
            temp = tab[i];
            tab[i] = tab[min_index];
            tab[min_index] = temp;
        }
        display_vector(tab, size);
        printf("\n");

    }
    return 0;

}


int selection_sort_desc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int temp;
    if (size == 1)
    {
        display_vector(tab, size);
        return 0;
    }

    //int min_index;
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (tab[j] > tab[min_index]) {
                min_index = j;
            }
        }


        if (min_index != i) {
            temp = tab[i];
            tab[i] = tab[min_index];
            tab[min_index] = temp;
        }
        display_vector(tab, size);
        printf("\n");

    }
    return 0;
}


int selection_sort(int tab[], int size, enum direction dir)
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
        selection_sort_asc(tab, size);
    }
    else {
        selection_sort_desc(tab, size);
    }
    display_vector(tab, size);
    printf("\n");
    return 0;
}
