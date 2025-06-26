#include <stdio.h>
#include "quicksort.h"
#include "vector_utils.h"
#include "types_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    int tab[50];
    printf("Podaj wektor:\n");
    int vec_prov = read_vector(tab, 50, 0);
    if (vec_prov == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    else if (vec_prov == -1 || vec_prov == 0) {
        printf(" Not enough data available");
        return 3;
    }
    int kierunek;
    printf("Podaj kierunek sortowania:");
    if (!scanf("%d", &kierunek)) {
        printf("Incorrect input");
        return 1;
    }
    if (kierunek != 1 && kierunek != 2) {
        printf("Incorrect input data");
        return 2;
    }
    int ret;
    if (kierunek == 1) {
        ret = quicksort(tab, vec_prov, ASCENDING);
    }
    if (kierunek == 2) {
        ret = quicksort(tab, vec_prov, DESCENDING);
    }
    /*int input_array[] = {-4, -8, -1, -2, -4, 0, 0, -8, 0, -5, -8, -5, -9, -10, -3, -8, -1, 0};
    int ges = quicksort_asc(0, 14, input_array, 15);
    display_vector(input_array, 15);*/
    display_vector(tab, vec_prov);
    return ret;
}
//-97 -95 -84 -72 -72 -70 -67 -61 -59 -53 -53 -50 -48 -46 -41 -40 -32 -30 -27 -21 -19 -18 -5 -5 -3 -2 -2 8 11 13 18 26 30 33 34 36 45 54 57 58 60 64 66 69 74 80 80 91 91 93 0

