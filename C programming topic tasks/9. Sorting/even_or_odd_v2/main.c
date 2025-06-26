#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


int sort_odd_asc_even_desc(int tab[], int size)
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
    int il_nepar = 0;
    int i, j = size - 1;
    for(i = 0; i < size; i++)
    {
        if(tab[i]%2!=0)
        {
            il_nepar++;
        }
    }
    for (i = 0; i < size-1 && i != il_nepar; i++)
    {
        if (tab[i] % 2 != 0)
        {
            continue;
        }
        else
        {

            while (tab[j]%2 == 0)
            {
                j--;
            }
            swap(&tab[i], &tab[j]);
        }

    }

    //display_vector(tab, size);
    //printf("\n\n");





    int g;
    for (g = 0; g < il_nepar; g++)
    {
        zamen = 0;
        for (j = 0; j < il_nepar - g-1; j++)
        {
            if (tab[j]>tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                zamen += 1;
            }
        }
        if (zamen == 0)
        {
            break;
        }

    }



    //display_vector(tab, size);
    //printf("\n\n");

    for (g = il_nepar; g < size; g++)
    {
        zamen = 0;
        for (j = il_nepar; j < size -1; j++)
        {
            if (tab[j]<tab[j+1])
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
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
    sort_odd_asc_even_desc(tab, vec_prov);
    display_vector(tab, vec_prov);
    return 0;
}

