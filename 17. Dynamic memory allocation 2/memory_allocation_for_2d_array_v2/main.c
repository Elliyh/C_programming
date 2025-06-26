#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int create_array_2d_2(int ***ptr, int width, int height);
void destroy_array_2d(int ***ptr, int height);
void display_array_2d(int **ptr, int width, int height);
int sum_array_2d(int **ptr, int width, int height);
int sum_row(int *ptr, int width);

int main() {
    int ** ukaz;
    printf("Podaj szerokość i wysokość:");
    int width, height;
    if(scanf("%d %d", &width, &height) != 2)
    {
        printf("incorrect input");
        return 1;
    }
    if(height<= 0 || width <= 0)
    {
        printf("incorrect input data");
        return 2;

    }
    create_array_2d_2(&ukaz, width, height);
    if(ukaz == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    printf("Podaj liczby:");
    int i, j, number;
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            if(!scanf("%d", &number))
            {
                destroy_array_2d(&ukaz, height);
                printf("incorrect input");
                return 1;
            }
            *(*(ukaz+i)+j) = number;
        }
    }
    display_array_2d(ukaz, width, height);
    for(i = 0; i < height; i++){
        printf("%d\n", sum_row(*(ukaz+i), width));
    }
    printf("%d\n", sum_array_2d(ukaz, width, height));
    destroy_array_2d(&ukaz, height);
    return 0;
}

int create_array_2d_2(int ***ptr, int width, int height)
{
    if(width <= 0 || height <= 0 || ptr == NULL) //*ptr == NULL
        return 1;

    int **rows = malloc(height * sizeof(int*));
    if (rows == NULL)
    {
        return 2;
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
            return 2;
        }
    }
    *ptr = rows;
    return 0;
}

void destroy_array_2d(int ***ptr, int height)
{
    if(ptr == NULL || height <= 0)
        return;
    for(int i = 0; i < height; i++) {
        free(*(*ptr+i));
    }
    free(*ptr);
    *ptr = NULL;
}


void display_array_2d(int **ptr, int width, int height)
{
    if(ptr == NULL || width <= 0 || height <= 0) //*ptr == NULL
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

int sum_row(int *ptr, int width)
{
    if(ptr == NULL || width <= 0)
        return -1;
    int sum = 0;
    for(int i = 0; i < width; i++)
    {
        sum+= *(ptr+i);
    }
    return sum;
}

int sum_array_2d(int **ptr, int width, int height)
{
    if(width <= 0 || height <= 0 || ptr == NULL) //*ptr == NULL
        return -1;
    int i, j, sum = 0;
    for(i = 0; i< height; i++)
    {
        for(j = 0; j < width; j++)
        {
            sum += *(*(ptr+i)+j);
        }
    }
    return sum;
}


