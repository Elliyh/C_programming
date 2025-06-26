#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    int **rows = malloc(10 * sizeof(int*));
    if(rows == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int i, j;
    for(i = 0; i < 10; i++)
    {
        *(rows+i) = malloc(sizeof(int) * 10);
        if(*(rows+i) == NULL)
        {
            for(int g = i-1; g >= 0; g -- )
            {
                free(*(rows+g));
            }
            free(rows);
            printf("Failed to allocate memory");
            return 8;
        }
    }
    for(i = 0; i< 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            *(*(rows+i)+j) = (i+1)*(j+1);
        }
    }
    for(i = 0; i< 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            printf("%3d ", *(*(rows+i)+j));
        }
        printf("\n");
        free(*(rows+i));
    }
    free(rows);
    return 0;
}

