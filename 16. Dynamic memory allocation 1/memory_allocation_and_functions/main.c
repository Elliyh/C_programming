#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"


float* create_array(int N)
{
    if(N <= 0)
        return NULL;
    float* tablica = malloc(N * sizeof(float));
    if(tablica == NULL)
        return NULL;
    return tablica;
}

int main() {
    printf("Podaj rozmiar tablicy: ");
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
    float *adres = create_array(size);
    if(adres == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj liczby: ");
    for(int i = 0; i < size; i++)
    {
        if(!scanf("%f", (adres+i)))
        {
            printf("Incorrect input");
            free(adres);
            return 1;
        }
    }
    for(int i = size-1; i >= 0; i--)
    {
        printf("%.4f ", *(adres+i));
    }
    free(adres);
    return 0;
}

