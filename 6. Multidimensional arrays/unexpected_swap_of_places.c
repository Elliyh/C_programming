#include <stdio.h>

int main() {
    printf("Podaj macierz 5x5:\n");
    int macierz [5][5];
    int proverka = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (scanf("%d", &macierz[i][j]) != 1)
            {
                proverka += 1;
            }
        }
    }
    if(proverka != 0)
    {
        printf("incorrect input");
        return 1;
    }

    int vremenno;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                vremenno = macierz[i][4-i];
                macierz[i][4-i] = macierz[i][i];
                macierz[i][i] = vremenno;
            }
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
    return 0;
}
