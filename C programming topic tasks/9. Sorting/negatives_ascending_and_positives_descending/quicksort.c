#include <stdio.h>
#include "quicksort.h"
#include "vector_utils.h"
#include "types_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



int quicksort_asc(int l, int r, int tab[], int tabSize)
{
    if (r > tabSize-1)
        return 1;
    if (tabSize < 1 || l < 0 || r < 0)
    {
        return 1;
    }
    if (tabSize == 1)
    {
        //display_vector(tab, tabSize);
        return 0 ;
    }

    if (l >= r) {
        return 0;
    }

    int pivot = tab[r];
    int i, granica = l;
    for(i = l; i < r; i++)
    {
        if (tab[i] <= pivot)
        {
            if (i != granica)
                swap(&tab[i], &tab[granica]);
            granica++;
        }
    }
    if (r != granica)
        swap(&tab[r], &tab[granica]);
    if (l < granica - 1)
    {
        quicksort_asc(l, granica - 1, tab, tabSize);
    }

    if (granica + 1 < r)
    {
        quicksort_asc(granica + 1, r, tab, tabSize);
    }

    return 0;
}


int quicksort_desc(int l, int r, int tab[], int tabSize)
{
    if (r > tabSize-1)
        return 1;
    if (tabSize < 1 || l < 0 || r < 0)
    {
        return 1;
    }
    if (tabSize == 1)
    {
        //display_vector(tab, tabSize);
        return 0;
    }

    if (l >= r) {
        return 0;
    }

    int pivot = tab[r];
    int i, granica = l;
    for(i = l; i < r; i++)
    {
        if (tab[i] >= pivot)
        {
            if (i != granica)
                swap(&tab[i], &tab[granica]);
            granica++;
        }
    }
    if (r != granica)
        swap(&tab[r], &tab[granica]);
    if (l < granica - 1)
    {
        quicksort_desc(l, granica - 1, tab, tabSize);
    }

    if (granica + 1 < r)
    {
        quicksort_desc(granica + 1, r, tab, tabSize);
    }

    return 0;
}



int quicksort(int tab[], int size, enum direction dir)
{


    if (size <= 0 || (dir != ASCENDING && dir != DESCENDING))
    {
        return 1;
    }
    if (size == 1)
    {
        return 0;
    }
    if (dir == ASCENDING)
    {
        quicksort_asc(0, size-1, tab, size);
    }
    else {
        quicksort_desc(0, size-1, tab, size);
    }
    return 0;
}
