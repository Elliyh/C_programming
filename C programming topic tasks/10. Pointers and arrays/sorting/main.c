#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}



int sort(int* tab, int size)
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




int main() {
    printf("Wpisuj wartosci calkowite\n");
    int tab [100] = {0};
    int* T = tab;
    int size = read_vector(T, 100, -1);
    if (size == -1 || size == 0)
    {
        printf("Not enough data available");
        return 3;
    }
    else if (size == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    sort(T, size);
    display_vector(T, size);

    return 0;
}

