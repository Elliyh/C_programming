#include <stdio.h>
#include "sort.h"
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"





int main() {
    int tab [50];
    printf("Podaj wektor:\n");
    int vec_prov = read_vector(tab, 50, 0);
    if (vec_prov == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (vec_prov == -1 || vec_prov == 0)
    {
        printf(" Not enough data available");
        return 3;
    }
    int kierunek;
    printf("Podaj kierunek sortowania:");
    if(!scanf("%d", &kierunek))
    {
        printf("Incorrect input");
        return 1;
    }
    if (kierunek != 1 && kierunek != 2)
    {
        printf("Incorrect input data");
        return 2;
    }
    if (kierunek == 1)
    {
        bubble_sort(tab, vec_prov, ASCENDING);
    }
    if (kierunek == 2)
    {
        bubble_sort(tab, vec_prov, DESCENDING);
    }
    return 0;
}

