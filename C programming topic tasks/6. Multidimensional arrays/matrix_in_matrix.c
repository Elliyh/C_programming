#include <stdio.h>

int main() {
    printf("Podaj liczby:\n");
    int i, j, proverka = 0;
    int massive [10][10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (scanf("%d", &massive[i][j]) != 1)
            {
                proverka += 1;
            }
        }
    }
    if (proverka != 0)
    {
        printf("incorrect input");
        return 1;
    }
    int massive2 [2][2];
    printf("Podaj liczby:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            if (scanf("%d", &massive2[i][j]) != 1)
            {
                proverka += 1;
            }
        }
    }
    if (proverka != 0)
    {
        printf("incorrect input");
        return 1;
    }

    int kol_macierz = 0, podscet = 0;
    int znacz [1000];

    for (i = 0; i < 9; i++)
    {
        for (j= 0; j < 9; j++)
        {
            if (massive[i][j] == massive2[0][0] && massive[i][j+1] == massive2[0][1] &&
                    massive[i+1][j] == massive2[1][0] && massive[i+1][j+1] == massive2[1][1])
            {
                kol_macierz += 1;
                znacz[podscet] = i;
                znacz[podscet+1] = j;
                podscet += 2;
            }
        }
    }

    printf("%d\n", kol_macierz);

    for (int f = 0; f < podscet; f += 2)
    {
        printf("%d %d\n", znacz[f+1], znacz[f]);
    }

}

