#include <stdio.h>

int main() {
    printf("podaj liczby:\n");
    int macierz[10][10];
    int max = 0;
    int i, j, proverka = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (scanf("%d", &macierz[i][j]) != 1) {
                proverka += 1;
            }
            if (macierz[i][j] % 2 == 0 && max != 0)
            {
                if (max < macierz[i][j])
                {
                    max = macierz[i][j];
                }

            }
            else if (macierz[i][j] % 2 == 0 && max == 0)
            {
                max = macierz[i][j];
            }
        }
    }

    if (proverka != 0) {
        printf("incorrect input");
        return 1;
    }
    if (max == 0)
    {
        printf("Nothing to show");
    }


    int sum_wer = 0, sum_kol = 0;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++)
        {
            if (macierz[i][j] == max)
            {
                for (int g = 0; g < 10; g++)
                {
                    sum_wer += macierz[i][g];
                }
                for (int f = 0; f < 10; f++)
                {
                    sum_kol += macierz[f][j];
                }
                printf("%d %d %d\n", j, i, sum_wer - sum_kol);
                sum_wer = 0;
                sum_kol = 0;
            }
        }
    }



    return 0;
}
