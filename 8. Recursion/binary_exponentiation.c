#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

long long binary_exponentiation(long long x, unsigned int n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        long long int result = binary_exponentiation(x, n / 2);
        return result * result;
    }
    else {
        long long int result = binary_exponentiation(x, (n - 1) / 2);
        return x * result * result;
    }
}

int main() {
    int x, n;
    printf("Podaj podstawe:");
    if (scanf("%d", &x) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj wykladnik:");
    if(scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }

    if (n < 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("Wynik: %lld", binary_exponentiation(x, n));
    return 0;
}

