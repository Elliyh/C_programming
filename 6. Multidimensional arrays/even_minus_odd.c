#include <stdio.h>

int main() {
    printf("podaj liczby:\n");
    int macierz[10][10];
    int sum_par = 0, sum_nepar = 0;
    int i, j, proverka = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (scanf("%d", &macierz[i][j]) != 1) {
                proverka += 1;
            }
            if ((i+j)%2 == 0)
            {
                sum_par += macierz[i][j];
            }
            else
            {
                sum_nepar += macierz[i][j];
            }


        }
    }

    if (proverka != 0) {
        printf("incorrect input");
        return 1;
    }

    printf("%d", sum_par - sum_nepar);

    return 0;
}