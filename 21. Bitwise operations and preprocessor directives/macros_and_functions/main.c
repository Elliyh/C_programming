#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

CREATE_READ_FUNCTIONS(int, "%d")
CREATE_SORT_FUNCTIONS(int)
CREATE_DISPLAY_FUNCTIONS(int, "%d")
CREATE_READ_FUNCTIONS(float, "%f")
CREATE_SORT_FUNCTIONS(float)
CREATE_DISPLAY_FUNCTIONS(float, "%f")
CREATE_READ_FUNCTIONS(double, "%lf")
CREATE_SORT_FUNCTIONS(double)
CREATE_DISPLAY_FUNCTIONS(double, "%lf")

int main() {
    printf("Choose your type:");
    int type;
    if(scanf("%d", &type) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if(type < 0 || type > 2)
    {
        printf("Incorrect input data");
        return 2;
    }
    int size;
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1) {
        printf("Incorrect input");
        return 1;
    }
    else if(size <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    void *massive = NULL;
    if(type == 0)
            massive = calloc(size, sizeof(int));
    else if(type == 1)
            massive = calloc(size, sizeof(float));
    else if(type == 2)
            massive = malloc(size * sizeof(double));
    if(massive == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }

    int spraw;
    printf("Podaj liczby:");
    if(type == 0)
        spraw = read_int((int *)massive, size);
    else if(type == 1)
        spraw = read_float((float *)massive, size);
    else
        spraw = read_double((double *)massive, size);


    if (spraw == 1)
    {
        printf("Incorrect input data");
        free(massive);
        return 2;
    }
    else if (spraw == 2)
    {
        printf("Incorrect input");
        free(massive);
        return 1;
    }


    if(type == 0)
    {
        sort_int((int *)massive, size);
        display_int((int *)massive, size);
    }
    else if(type == 1)
    {
        sort_float((float *)massive, size);
        display_float((float *)massive, size);
    }
    else
    {
        sort_double((double *)massive, size);
        display_double((double *)massive, size);
    }

    free(massive);
    return 0;
}

