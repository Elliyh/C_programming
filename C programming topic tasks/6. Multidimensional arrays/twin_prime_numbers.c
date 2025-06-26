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


int is_twin(int a, int b)
{

    if (a + 2 != b && a - 2 != b)
    {
        return 0;
    }

    if (is_prime(a) == 1 && is_prime(b) == 1)
    {
        return 1;
    }
    else
        return 0;
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
    for (int i = x1+2; i <= x2; i++) {
        if (is_prime(i))
        {
            if (is_twin(i-2, i))
            {
                printf("%d, %d\n", i-2, i);
                proverka += 1;
            }
        }
    }

    if (proverka == 0)
    {
        printf("Nothing to show");
    }


    return 0;
}
