#include "vector_utils.h"
#include "quicksort.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int read_vector(int vec[], int size, int stop_value)
{
    int i;
    int rozmiar = 0;
    if (size <= 0)
        return -1;
    for (i = 0; i < size; i++)
    {
        if (scanf("%d", &vec[rozmiar]) == 1)
        {
            if (vec[rozmiar] == stop_value)
            {
                break;
            }
            rozmiar += 1;
        }
        else
            return -2;
    }

    if (i <= size)
    {
        int a;
        while((a=getchar()) != '\n'){}
    }
    return rozmiar;

}

void display_vector(const int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", vec[i]);
    }
}
