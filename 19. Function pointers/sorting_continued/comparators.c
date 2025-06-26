#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"



int comp_int(const void *ptr1, const void *ptr2)
{
    if(ptr1 == NULL || ptr2 == NULL)
        return 0;
    const int *int_ptr1 = (const int *)ptr1;
    const int *int_ptr2 = (const int *)ptr2;
    if(*int_ptr1 > *int_ptr2)
        return 1;
    else if(*int_ptr1 < *int_ptr2)
        return -1;
    else
        return 0;

}
int comp_double(const void *ptr1, const void *ptr2)
{
    if(ptr1 == NULL || ptr2 == NULL)
        return 0;
    const double *double_ptr1 = (const double *)ptr1;
    const double *double_ptr2 = (const double *)ptr2;
    if(*double_ptr1 > *double_ptr2)
        return 1;
    else if(*double_ptr1 < *double_ptr2)
        return -1;
    return 0;
}
int comp_point(const void *ptr1, const void *ptr2)
{
    if(ptr1 == NULL || ptr2 == NULL)
        return 0;
    const struct point_t *point_ptr1 = (const struct point_t *)ptr1;
    const struct point_t *point_ptr2 = (const struct point_t *)ptr2;
    if (point_ptr1->x > point_ptr2->x)
        return 1;
    else if (point_ptr1->x < point_ptr2->x)
        return -1;
    else if (point_ptr1->y > point_ptr2->y)
        return 1;
    else if (point_ptr1->y < point_ptr2->y)
        return -1;

    return 0;
}
int sort(void *adres, int size, int bytes, int (*comparator)(const void *, const void *))
{
    if(bytes <= 0 || adres == NULL || size <= 0 || comparator == NULL)
        return 1;
    int i, j;
    for(i = 0; i < size-1; i++)
    {
        for(j = 0; j < size-i-1; j++)
        {
            char *first = (char *)adres + j * bytes;
            char *second = (char *)adres + (j + 1) * bytes;
            int znacz = comparator(first, second);
            if(znacz > 0)
            {
                char* temp = malloc(bytes);
                memcpy(temp, first, bytes);
                memcpy(first, second, bytes);
                memcpy(second, temp, bytes);
                free(temp);

            }
        }
    }
    return 0;
}

