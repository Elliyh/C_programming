#include <stdio.h>
#include "vector_utils.h"
#include "vector_utils.h"
#include "quicksort.h"
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"


int sort_negative_asc_positive_desc(int tab[], int size)
{
    if (size < 1)
    {
        return 1;
    }
    if (size == 1)
    {
        //display_vector(tab, tabSize);
        return 0 ;
    }
    quicksort_asc(0, size-1, tab, size);
    int i;
    for (i = 0; i < size-1; i++)
    {
        if (tab[i] >= 0)
            break;
    }
    quicksort_desc(i, size-1, tab, size);
    return 0;
}

int main() {
    int tab[150];
    printf("Podaj wektor:\n");
    int vec_prov = read_vector(tab, 150, 0);
    if (vec_prov == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    else if (vec_prov == -1 || vec_prov == 0) {
        printf(" Not enough data available");
        return 3;
    }
    /*int liczba;
    printf("Podaj wartosc:");
    if (!scanf("%d", &liczba)) {
        printf("Incorrect input");
        return 1;
    }*/

    sort_negative_asc_positive_desc(tab, vec_prov);
    /*int input_array[] = {-4, -8, -1, -2, -4, 0, 0, -8, 0, -5, -8, -5, -9, -10, -3, -8, -1, 0};
    int ges = quicksort_asc(0, 14, input_array, 15);
    display_vector(input_array, 15);*/
    display_vector(tab, vec_prov);
}
//-97 -95 -84 -72 -72 -70 -67 -61 -59 -53 -53 -50 -48 -46 -41 -40 -32 -30 -27 -21 -19 -18 -5 -5 -3 -2 -2 8 11 13 18 26 30 33 34 36 45 54 57 58 60 64 66 69 74 80 80 91 91 93 0

