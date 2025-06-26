#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int sum_of_digits(long long number)
{
    if (number < 0)
    {
        number *= -1;
    }
    if (number < 10)
    {
        return number;
    }
    return sum_of_digits(number%10) + sum_of_digits(number/10);
}

int main() {
    printf("Podaj liczbe:");
    long long n;
    if (scanf("%lld", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if (n < 0)
    {
        n *= -1;
    }
    printf("Wynik: %d", sum_of_digits(n));
    return 0;
}

