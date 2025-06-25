#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

long power_rec(int a, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return a*power_rec(a, n-1);
}

int main() {
    int a, n;
    printf("Podaj a:");
    if (scanf("%d", &a) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj n:");
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (n < 0)
    {
        printf( "Incorrect input data");
        return 2;
    }
    printf("Wynik: %ld", power_rec(a, n));
    return 0;
}

