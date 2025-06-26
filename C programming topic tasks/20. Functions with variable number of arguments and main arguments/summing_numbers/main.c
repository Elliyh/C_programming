#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "tested_declarations.h"
#include "rdebug.h"

int stats(int *sum, float *avg, int num,...)
{
    if(sum == NULL || avg == NULL || num <= 0)
        return 1;
    *sum = 0;
    *avg = 0;
    va_list tab_args;
    va_start(tab_args, num);
    for(int i = 0; i < num; i++)
    {
        *sum += va_arg(tab_args, int);
    }
    va_end(tab_args);

    *avg = (float)*sum/(float)num;
    return 0;
}


int main() {
    int count;
    printf("Enter number of elements:");
    if(!scanf("%d", &count))
    {
        printf("Incorrect input");
        return 1;
    }
    if(count <= 0 || count >= 4)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("Enter numbers:");
    int *tab = calloc(count, sizeof(int));
    if(tab == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i = 0; i < count; i++)
        *(tab+i) = 0;
    for(int i = 0; i < count; i++)
    {
        if(!scanf("%d", (tab+i)))
        {
            printf("Incorrect input");
            free(tab);
            return 1;
        }
    }

    int sum;
    float avg;
    stats(&sum, &avg, count, *(tab), *(tab+1), *(tab+2));
    printf("%d %.6f", sum, avg);
    free(tab);
    return 0;
}

