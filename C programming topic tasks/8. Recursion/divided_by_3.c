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

int is_divisible_by_3(int number)
{
    int l = sum_of_digits(number);

    if (l >= 10) {
        return is_divisible_by_3(l);
    }
    return (l == 0 || l == 3 || l == 6 || l == 9);
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
    if (is_divisible_by_3(n))
    {
        printf("YES");
        return 0;
    }
    printf("NO");
    return 0;
}

