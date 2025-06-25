#include <stdio.h>
#include "vector_utils.h"
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"


int sort_by_distance(int tab[], int size, int v)
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

    int zamen, temp;
    for (int i = 0; i < size; i++)
    {
        zamen = 0;
        for (int j = 0; j < size - i-1; j++)
        {
            int r1 = fabs(tab[j] - v);
            int r1_1 = fabs(tab[j + 1] - v);

            if (r1 > r1_1)
            {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
                zamen += 1;
            }
        }
        if (zamen == 0)
        {
            break;
        }

    }
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
    int liczba;
    printf("Podaj wartosc:");
    if (!scanf("%d", &liczba)) {
        printf("Incorrect input");
        return 1;
    }

    sort_by_distance(tab, vec_prov, liczba);

    /*int input_array[] = {-4, -8, -1, -2, -4, 0, 0, -8, 0, -5, -8, -5, -9, -10, -3, -8, -1, 0};
    int ges = quicksort_asc(0, 14, input_array, 15);
    display_vector(input_array, 15);*/
    display_vector(tab, vec_prov);
}
//-97 -95 -84 -72 -72 -70 -67 -61 -59 -53 -53 -50 -48 -46 -41 -40 -32 -30 -27 -21 -19 -18 -5 -5 -3 -2 -2 8 11 13 18 26 30 33 34 36 45 54 57 58 60 64 66 69 74 80 80 91 91 93 0

