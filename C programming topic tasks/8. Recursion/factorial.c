#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long factorial_rec(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 1 || n == 0)
    {
        return 1;
    }
    return n*factorial_rec(n-1);
}

int main() {
    printf("Podaj n:");
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (n < 0 || n > 20)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("Wynik: %ld", factorial_rec(n));
    return 0;
}

