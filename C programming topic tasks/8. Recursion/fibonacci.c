#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

long int fibonacci(int n)
{
    if (n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}


int main() {
    printf("Który wyraz ciagu fibonacciego chcesz wyznaczyć:");
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (n < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Wynik: %ld", fibonacci(n));

    return 0;
}

