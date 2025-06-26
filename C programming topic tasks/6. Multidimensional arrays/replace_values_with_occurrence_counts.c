#include <stdio.h>

int main() {
    printf("podaj liczby:\n");
    int macierz [15][15];
    int massive_povtor [30] = {0};
    int i, j, proverka = 0, limit = 0;
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            if (scanf("%d", &macierz[i][j]) != 1)
            {
                proverka += 1;
            }
            else if (macierz[i][j] < 0 || macierz[i][j] >= 30)
            {
                limit += 1;
            }
            else
            {
                massive_povtor[macierz[i][j]] += 1;
            }
        }
    }

    if (limit != 0)
    {
        printf("value out of range");
        return 2;
    }
    if (proverka != 0)
    {
        printf("incorrect input");
        return 1;
    }
    for (i = 0; i < 15; i++)
    {
        for (j = 0; j < 15; j++)
        {
            printf("%d ", massive_povtor[macierz[i][j]]);
        }
        printf("\n");
    }


    return 0;
}
