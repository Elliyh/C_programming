#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("podaj liczby:\n");
    int macierz[10][10];
    int min = -32000, max = 32000;
    int kol_min = 0, kol_max = 0, kol_sred = 0;
    int vse = 0;
    int i, j, proverka = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (scanf("%d", &macierz[i][j])) {
                vse += macierz[i][j];
                if (min == -32000 && max == 32000)
                {
                    min = macierz[i][j];
                    max = macierz[i][j];
                }
                else if (min > macierz[i][j]){
                    min = macierz[i][j];
                }
                else if (max < macierz[i][j])
                {
                    max = macierz[i][j];
                }

            }
            else
            {
                proverka++;
            }
        }
    }
    float sred = (float)vse/(float)100;

    if (proverka != 0)
    {
        printf("incorrect input");
        return 1;
    }


    int blize = 1000000;
    int dlina;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (abs(sred - macierz[i][j]) <= dlina)
            {
                dlina = abs(sred - macierz[i][j]);
                blize = macierz[i][j];
            }
        }
    }


    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (macierz[i][j] == max)
            {
                kol_max++;
            }
            else if (macierz[i][j] == min)
            {
                kol_min++;
            }
            else if (macierz[i][j] == blize)
            {
                kol_sred++;
            }
        }
    }

    if (kol_max != 1 || kol_min != 1 || kol_sred != 1)
    {
        printf("error");
        return 2;
    }


    int kord [6];

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (macierz[i][j] == min)
            {
                kord[0] = i;
                kord[1] = j;
            }
            else if (macierz[i][j] == max)
            {
                kord[2] = i;
                kord[3] = j;
            }
            else if (macierz[i][j] == blize)
            {
                kord[4] = i;
                kord[5] = j;
            }
        }
    }

    double min_max = sqrt(pow((kord[0] - kord[2]), 2)+pow(kord[1]-kord[3], 2));
    double min_blize = sqrt(pow((kord[0] - kord[4]), 2)+pow(kord[1]-kord[5], 2));
    double max_blize = sqrt(pow((kord[2] - kord[4]), 2)+pow(kord[3]-kord[5], 2));

    printf("%.2f %.2f %.2f", min_max, min_blize, max_blize);


    return 0;
}

/*
90 1 -33 -95 -15 -23 79 60 17 52
-18 -6 -75 72 -44 -79 -22 65 79 75
-51 -64 -63 74 36 24 -3 29 -79 -48
-26 -26 9 67 -36 31 -79 -65 17 -8
28 26 -89 -56 -8 90 -13 81 -61 26
18 -75 -94 -82 51 74 44 48 15 -68
-4 -72 21 90 -65 83 -80 51 -60 -8
100 33 -56 74 -75 49 16 -19 83 19
25 -45 -1 87 -82 -47 -41 -45 18 85
33 -91 -30 -25 52 69 -88 1 -28 52
 */