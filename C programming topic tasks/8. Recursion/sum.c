#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long sum_rec(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    return n+sum_rec(n-1);
}



int main() {
    printf("Podaj liczbę, dla której chcesz policzyć sumę:");
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (n <= 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Wynik: %ld", sum_rec(n));
    return 0;
}

