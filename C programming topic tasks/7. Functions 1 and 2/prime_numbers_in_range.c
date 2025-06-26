#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_prime(int a) {
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

int main() {
    int x1, x2;
    printf("Podaj x1=");
    if ((scanf("%d", &x1)) == 0) {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj x2=");
    if ((scanf("%d", &x2)) == 0) {
        printf("Incorrect input");
        return 1;
    }
    if (x1 > x2) {
        printf("Incorrect input");
        return 1;
    }

    int proverka = 0;
    for (int i = x1; i <= x2; i++) {
        if (is_prime(i))
        {
            printf("%d ", i);
            proverka += 1;
        }
    }

    if (proverka == 0)
    {
        printf("Nothing to show");
    }


    return 0;
}

