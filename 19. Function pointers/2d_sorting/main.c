#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    printf("Enter width and height:");
    int width, height;
    if(scanf("%d %d", &width, &height) != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    if(width <= 0 || height <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    int** tab = calloc(height, sizeof(int*));
    if(tab == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i = 0; i < height; i++)
    {
        *(tab+i) = calloc(width, sizeof(int));
        if(*(tab+i) == NULL)
        {
            for(int g = i-1; g >= 0; g--)
                free(*(tab+g));
            free(tab);
            printf("Failed to allocate memory");
            return 8;
        }
    }

    printf("Enter data:\n");

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(!scanf("%d", (*(tab+i)+j)))
            {
                printf("Incorrect input");
                free_tab(tab, width, height);
                return 1;
            }
        }
    }
    printf("Selection choice:");
    int choice;
    if(!scanf("%d", &choice))
    {
        printf("Incorrect input");
        free_tab(tab, width, height);
        return 1;
    }
    if(choice != 0 && choice != 1 && choice != 2)
    {
        printf("Incorrect input data");
        free_tab(tab, width, height);
        return 2;
    }

    int (*functions[])(const int*, const int*, int) = {comp_min, comp_max, comp_sum};

    sort_rows(tab, width, height, *(functions+choice));

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            printf("%d ", *(*(tab+i)+j));
        }
        printf("\n");
    }
    free_tab(tab, width, height);
    return 0;
}

/*
 1    -13 361 -95 -452  -1   -7    2  166   59
-273  68  68  43   11 999   52   -7   -5    6
416    3 284 -83   -1 -80 -728  -26    6  -55
1      1  10 -10  935 -75  746   -7    0   -9
9    -27  57   5   89   2   38 -813 -499 -885
 */

