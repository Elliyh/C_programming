#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long long decimal_to_octal(unsigned int number)
{
    if (number == 0)
        return 0;
    return (decimal_to_octal(number / 8) * 10) + (number % 8);

}

int main() {
    printf("Podaj liczbe:");
    int n;
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%llu", decimal_to_octal(n));
    return 0;
}

