#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"



int main() {
    printf("Podaj liczby:");
    float tab [100] = {0};
    float* T = tab;
    int size = read_vector_float(T, 100, -1);
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

    sort(T, size);


    int histograma [11] = {0};
    int* H = histograma;

    create_histogram(T, size, H, 11);

    display_vector(H, 11);
    return 0;
}

