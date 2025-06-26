#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int comp_min(const int *ptr1, const int *ptr2, int width)
{
    if(ptr1 == NULL || ptr2 == NULL || width <= 0)
        return 2;

    int i;
    int min1 = *ptr1, min2 = *ptr2;
    for(i = 0; i < width; i ++)
    {
        if(*(ptr1+i) < min1)
        {
            min1 = *(ptr1+i);
        }
        if(*(ptr2+i) < min2)
        {
            min2 = *(ptr2+i);
        }
    }
    if(min1 > min2)
        return 1;
    else if(min1 == min2)
        return 0;
    else
        return -1;
}
int comp_max(const int *ptr1, const int *ptr2, int width)
{
    if(ptr1 == NULL || ptr2 == NULL || width <= 0)
        return 2;
    int i;
    int max1 = *ptr1, max2 = *ptr2;
    for(i = 0; i < width; i ++)
    {
        if(*(ptr1+i) > max1)
        {
            max1 = *(ptr1+i);
        }
        if(*(ptr2+i) > max2)
        {
            max2 = *(ptr2+i);
        }
    }
    if(max1 > max2)
        return 1;
    else if(max1 == max2)
        return 0;
    else
        return -1;
}
int comp_sum(const int *ptr1, const int *ptr2, int width)
{
    if(ptr1 == NULL || ptr2 == NULL || width <= 0)
        return 2;
    int i;
    int sum1 = 0, sum2 = 0;
    for(i = 0; i < width; i ++)
    {
        sum1 += *(ptr1+i);
        sum2 += *(ptr2+i);
    }
    if(sum1 > sum2)
        return 1;
    else if(sum1 == sum2)
        return 0;
    else
        return -1;
}

int sort_rows(int** tab, int width, int height, int (*function)(const int*, const int*, int))
{
    if(tab == NULL || *tab == NULL || width <= 0 || height <= 0 || function == NULL)
        return 1;

    int i, j;
    for(i = 0; i < height-1; i++)
    {
        for(j = 0; j < height-i-1; j++)
        {
            if(function(*(tab+j), *(tab+j+1), width) == 1)
            {
                int* temp = *(tab+j);
                *(tab+j) = *(tab+j+1);
                *(tab+j+1) = temp;
            }
        }
    }
    return 0;
}

void free_tab(int** tab, int width, int height)
{
    if(tab == NULL || *tab == NULL || width <= 0 || height <= 0)
        return;
    for(int i = 0; i < height; i++)
    {
        free(*(tab+i));
    }
    free(tab);
}
