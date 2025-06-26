#include <stdio.h>

int main() {
    printf("Podaj liczby:\n");
    int i, j, proverka = 0;
    int massive [5][5];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
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

    int podscet = 0;
    int wywod [10];
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                wywod[podscet] = massive[i][j];
            }
            else if (wywod[podscet] < massive[i][j])
            {
                wywod[podscet] = massive[i][j];
            }
        }
        podscet += 1;
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                wywod[podscet] = massive[j][i];
            }
            else if (wywod[podscet] < massive[j][i])
            {
                wywod[podscet] = massive[j][i];
            }
        }
        podscet += 1;
    }

    for (int g = 0; g < 10; g++)
    {
        printf("%d ", wywod[g]);
    }


    return 0;
}

