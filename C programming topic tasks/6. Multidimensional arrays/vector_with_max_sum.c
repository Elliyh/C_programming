#include <stdio.h>
#include <math.h>

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

    printf("Podaj liczby:\n");
    int wektor [4] = {0};
    int g;

    for (g = 0; g < 4; g++)
    {

        if (scanf("%d", &wektor[g]) != 1)
        {
            proverka += 1;
        }
        else if (wektor[g] == 0)
        {
            break;
        }

    }

    if (proverka != 0)
    {
        printf("incorrect input");
        return 1;
    }

    int podscet = 0, nacialo  = 2;
    int wywod [4][500];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 500; j++)
        {
            wywod[i][j] = 0;
        }
    }


    for (int f = 0; f < g; f++)
    {
        wywod[f][0] = f;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 10; j++)
            {
                if (pow(wektor[f], 2) == massive[i][j])
                {
                    podscet += 1;
                    wywod[f][nacialo] = j;
                    wywod[f][nacialo+1] = i;
                    nacialo += 2;
                }
            }
        }
        wywod[f][1] = podscet;
        podscet = 0;
        nacialo = 2;
    }

    if (wektor[0] == 0)
    {
        printf("not enough data available");
        return 2;
    }

    for (int f = 0; f < g; f++)
    {
        for (i = 0; i < (wywod[f][1] * 2) + 2; i += 2)
        {
            printf("%d %d ", wywod[f][i], wywod[f][i+1]);
        }
        printf("\n");
    }


    return 0;
}

/*
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2
 */