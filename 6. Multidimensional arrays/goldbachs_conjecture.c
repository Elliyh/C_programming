#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "expected_prototypes.h"

int czy_pierwsza(int a) {
    if (a <= 1)
    {
        return 0;
    }
    int *massive = (int *) malloc((a + 1) * sizeof(int));

    for (int i = 0; i <= a; i++) {
        massive[i] = i;
    }
    massive[1] = 0;

    for (int i = 0; i <= a; i++) {
        if (massive[i] != 0) {
            int j = i + i;
            while (j <= a) {
                massive[j] = 0;
                j = j + i;
            }
        }
    }

    if (massive[a] == 0) {
        free(massive);
        return 0;
    }
    else
    {
        free(massive);
        return 1;
    }
}

int goldbach(int x)
{
    if (x%2 == 1)
    {
        return 0;
    }
    int proverka = 0;
    for (int i = 1; i < x; i++)
    {
        if ((czy_pierwsza(i) == 1 && czy_pierwsza(x-i) == 1))
        {
            printf(" (%d, %d)", i, x - i);
            if (i == 2 && x - i == 2)
                return 1;
            proverka = 1;
            continue;
        }
    }
    return proverka;
}

int main() {
    int a, b;
    printf("Podaj x1=");
    if (scanf("%d", &a) == 0)
    {
        printf("Incorrect input!");
        return 1;
    }
    printf("Podaj x2=");
    if (scanf("%d", &b) == 0)
    {
        printf("Incorrect input!");
        return 1;
    }

    int i;
    for (i = a; i <= b; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d:", i);
            if (i > 2)
            {
                goldbach(i);
            }
            printf("\n");
        }
    }
    return 0;
}

