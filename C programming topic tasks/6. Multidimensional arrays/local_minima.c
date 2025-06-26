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

    int koord [128] = {0};
    int podscet = 0, il_min = 0;

    for (i = 1; i < 9; i++)
    {
        for (j = 1; j < 9; j++)
        {
            if (massive[i-1][j-1] > massive[i][j] && massive[i-1][j] > massive[i][j] &&
                    massive[i-1][j+1] > massive[i][j] && massive[i][j-1] > massive[i][j] &&
                    massive[i][j+1] > massive[i][j] && massive[i+1][j-1] > massive[i][j] &&
                    massive[i+1][j] > massive[i][j] && massive[i+1][j+1] > massive[i][j])
            {
                il_min += 1;
                koord[podscet] = i;
                koord[podscet+1] = j;
                podscet += 2;
            }
        }
    }

    if (il_min == 0)
    {
        printf("Nothing to show");
        return 0;
    }

    printf("%d\n", il_min);

    for (int g = 0; g <= podscet && koord[g] != 0; g+=2)
    {
        printf("%d %d\n", koord[g], koord[g+1]);
    }


    return 0;
}
