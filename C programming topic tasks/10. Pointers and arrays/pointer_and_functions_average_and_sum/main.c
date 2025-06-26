#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int sum(const float* tab, unsigned int size, float *result)
{
    if (tab == NULL || size <= 0 || result == NULL)
        return 1;

    *result = 0;
    unsigned int i;
    for (i = 0; i < size; i++)
    {
        *result += *tab;
        tab++;
    }

    return 0;
}
int avg(const float* tab, unsigned int size, float *result)
{
    if (tab == NULL || size <= 0 || result == NULL)
        return 1;

    unsigned int i;
    float suma = 0;
    for (i = 0; i < size; i++)
    {
        suma += *tab;
        tab++;
    }

    *result = suma/size;

    return 0;
}
int read_vector_float(float *vec, int size, float stop_value)
{
    if (size <= 0 || vec == NULL)
    {
        return -1;
    }
    int i;
    for (i = 0; i < size; i++)
    {
        if (!scanf("%f", vec))
        {
            return -2;
        }
        if (*vec == stop_value)
        {
            break;
        }
        vec++;

    }
    /*if (i == 0)
        return -1;*/
    return i;
}

int main() {
    float tab [100] = {0};
    float* T = tab;
    printf("Podaj liczby:\n");
    int size = read_vector_float(T, 100, 0);
    if (size == -1 || size == 0)
    {
        printf("Not enough data available");
        return 3;
    }
    else if (size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    float suma = 0, sred = 0;
    float* sum_ad = &suma;
    float* sred_ad = &sred;
    sum(tab, size, sum_ad);
    avg(tab, size, sred_ad);
    printf("Suma: %.2f\n", *sum_ad);
    printf("Suma: %.2f", *sred_ad);
    return 0;
}

