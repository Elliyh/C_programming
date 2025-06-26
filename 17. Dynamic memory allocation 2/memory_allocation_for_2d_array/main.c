#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int **create_array_2d(int width, int height)
{
    if(width <= 0 || height <= 0)
        return NULL;

    int **rows = malloc(height * sizeof(int*));
    if (rows == NULL)
    {
        return NULL;
    }
    int i;
    for(i = 0; i < height; i++)
    {
        *(rows+i) = malloc(sizeof(int) * width);
        if(*(rows+i) == NULL)
        {
            for(int g = i-1; g >= 0; g -- )
            {
                free(*(rows+g));
            }
            free(rows);
            return NULL;
        }
    }
    return rows;
}

void display_array_2d(int **ptr, int width, int height)
{
    if(ptr == NULL || width <= 0 || height <= 0)
    {
        return;
    }
    int i, j;
    for(i = 0; i< height; i++)
    {
        for(j = 0; j < width; j++)
        {
            printf("%d ", *(*(ptr+i)+j));
        }
        printf("\n");
    }
}

void destroy_array_2d(int **ptr, int height)
{
    if(ptr == NULL || height <= 0)
        return;
    for(int i = 0; i < height; i++) {
        free(*(ptr+i));
    }
    free(ptr);
}

int main() {
    printf("Podaj szerokość i wysokość:");
    int col, row;
    if(scanf("%d %d", &col, &row) != 2)
    {
        printf("incorrect input");
        return 1;
    }
    if(row <= 0 || col <= 0)
    {
        printf("incorrect input data");
        return 2;

    }
    int **tab = create_array_2d(col, row);
    if(tab == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int i, j, number;
    printf("Podaj liczby:");
    for(i = 0; i< row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(!scanf("%d", &number))
            {
                destroy_array_2d(tab, row);
                printf("incorrect input");
                return 1;
            }
            *(*(tab+i)+j) = number;
        }
    }
    display_array_2d(tab, col, row);
    destroy_array_2d(tab, row);
    return 0;
}



