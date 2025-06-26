#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"


void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}


int sort(char const*ptrs[], int size)
{
    if (ptrs == NULL || size <= 0)
    {
        return 1;
    }
    for(int i = 0; i<size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(strcmp(*(ptrs+j), *(ptrs+j+1)) > 0)
            {
                swap((char **) (ptrs + j), (char **) (ptrs + j + 1));
            }
        }
    }
    return 0;
}

int main() {
    printf("Podaj tytuły:\n");
    char** ukaz_massive = (char **)calloc(10, sizeof(char *));
    int i, j;
    for(i = 0; i < 10; i++)
    {
        *(ukaz_massive+i) = (char*) calloc(91, sizeof(char));
    }

    char symbol;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 90; j++)
        {

            scanf("%c", &symbol);
            if (symbol == '\n')
            {
                *(*(ukaz_massive+i)+j) = '\0';
                break;
            }
            *(*(ukaz_massive+i)+j) = symbol;
        }
        if (i == 0 && j == 0 && symbol == '\n')
        {
            int g;
            for (g = 0; g < 10; g++)
            {
                free(*(ukaz_massive + g));
            }
            free(ukaz_massive);
            printf("Not enough data available");
            return 3;
        }
        if (j == 0 && symbol == '\n')
        {
            break;
        }
        if (j == 90 && symbol != '\n')
        {
            *(*(ukaz_massive+i)+90) = '\0';
            while(getchar()!='\n'){}
        }

    }

    sort((const char**)ukaz_massive, i);

    int g;
    for (g = 0; g < 10; g++)
    {
        if (g < i)
            printf("%s\n", *(ukaz_massive+g));
        free(*(ukaz_massive + g));
    }
    free(ukaz_massive);





    return 0;
}

