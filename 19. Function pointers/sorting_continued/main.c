#include <stdio.h>
#include <stdlib.h>
#include "comparators.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"




int main() {
    printf("Enter data type:");
    int type;
    if(!scanf("%d", &type))
    {
        printf("Incorrect input");
        return 1;
    }
    if(type < 0 || type > 2)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("Enter array size:");
    int size;
    if(!scanf("%d", &size))
    {
        printf("Incorrect input");
        return 1;
    }
    if(size <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    if(type == 0)
    {
        int* ukaz = calloc(size, sizeof(int));
        if(ukaz == NULL)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("Enter ints: ");
        for (int i = 0; i < size; ++i) {
            if (!scanf("%d", (ukaz + i)))
            {
                printf("Incorrect input");
                free(ukaz);
                return 1;
            }
        }
        sort(ukaz, size, sizeof(int), comp_int);
        for(int i = 0; i < size; i++)
        {
            printf("%d ", *(ukaz+i));
        }
        free(ukaz);
    }
    else if(type == 1)
    {
        double* ukaz = calloc(size, sizeof(double));
        if(ukaz == NULL)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("Enter doubles: ");
        for (int i = 0; i < size; ++i) {
            if (!scanf("%lf", (ukaz + i)))
            {
                printf("Incorrect input");
                free(ukaz);
                return 1;
            }
        }
        sort(ukaz, size, sizeof(double), comp_double);
        for(int i = 0; i < size; i++)
        {
            printf("%lf ", *(ukaz+i));
        }
        free(ukaz);
    }
    else
    {
        struct point_t* ukaz = calloc(size, sizeof(struct point_t));
        if(ukaz == NULL)
        {
            printf("Failed to allocate memory");
            return 8;
        }
        printf("Enter points: ");
        for (int i = 0; i < size; ++i)
        {
            if (scanf("%lf %lf", &(ukaz+i)->x, &(ukaz+i)->y) != 2) {
                printf("Incorrect input");
                free(ukaz);
                return 1;
            }
        }
        sort(ukaz, size, sizeof(struct point_t), comp_point);
        for(int i = 0; i < size; i++)
        {
            printf("%lf %lf\n", (ukaz+i)->x, (ukaz+i)->y);
        }
        free(ukaz);
    }

    return 0;
}


