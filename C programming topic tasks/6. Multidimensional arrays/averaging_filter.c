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
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            float new;
            new = (massive[i][j] + massive[i][j + 1] + massive[i][j + 2] + massive[i + 1][j] + massive[i + 1][j + 1] +
                   massive[i + 1][j + 2] + massive[i + 2][j] + massive[i + 2][j + 1] + massive[i + 2][j + 2]) / 9.0;
            printf("%.2f ", new);
        }
        printf("\n");
    }

    return 0;
}


/*6 3 5 3 1 9 5 5 6 2
4 5 5 2 6 5 8 6 8 5
1 4 6 5 4 1 2 3 4 8
7 2 5 8 4 5 8 5 9 3
6 10 9 5 4 8 5 1 3 7
2 10 2 10 3 4 2 9 6 2
4 2 5 7 7 2 5 10 7 7
1 2 3 1 8 1 8 2 3 10
1 6 8 8 5 9 1 8 10 8
4 8 3 8 6 9 4 10 10 6*/