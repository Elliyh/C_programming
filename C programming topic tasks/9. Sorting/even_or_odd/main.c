#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int sort_odd_desc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int temp;
    int zamen = 0;
    if (size == 1)
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        zamen = 0;
        for (int j = 1; j < size - i-2; j+=2)
        {
            if (tab[j] < tab[j+2])
            {
                temp = tab[j];
                tab[j] = tab[j+2];
                tab[j+2] = temp;
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


int sort_even_asc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    int temp;
    int zamen = 0;
    if (size == 1)
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        zamen = 0;
        for (int j = 0; j < size - i-2; j+=2)
        {
            if (tab[j]>tab[j+2])
            {
                temp = tab[j];
                tab[j] = tab[j+2];
                tab[j+2] = temp;
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

int main() {
    int tab [150];
    printf("Podaj wektor:\n");
    int vec_prov = read_vector(tab, 150, 0);
    if (vec_prov == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (vec_prov == -1 || vec_prov == 0)
    {
        printf(" Not enough data available");
        return 3;
    }

    sort_odd_desc(tab, vec_prov);
    sort_even_asc(tab, vec_prov);
    display_vector(tab, vec_prov);
    return 0;
}

