#include <stdio.h>

int main() {

    float T[100];
    int i, il_liczb;
    float* ukaz = T;
    float sum = 0;

    printf("Ile liczb chcesz wprowadzić?:");
    if (scanf("%d", &il_liczb) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if (il_liczb <= 0 || il_liczb > 100)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Podaj liczby:");

    for (i = 0; i < il_liczb; i++)
    {
        if (scanf("%f", ukaz) == 0)
        {
            printf("Incorrect input");
            return 1;
        }
        sum += *ukaz;
        ukaz++;
    }
    ukaz--;

    for (i = 0; i < il_liczb; i++)
    {
        printf("%.6f ", *ukaz);
        ukaz--;
    }
    printf("\n");
    printf("Suma: %.2f\nSrednia: %.2f", sum, sum/il_liczb);


    return 0;
}
