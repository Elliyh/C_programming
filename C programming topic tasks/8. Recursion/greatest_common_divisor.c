#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int GCD(int a, int b)
{
    if (a < 0)
    {
        a = a * -1;
    }
    if (b < 0)
    {
        b = b * -1;
    }
    if (b == 0)
        return a;

    return GCD(b, a%b);
}



int main() {
    int a, b;
    printf("Podaj a:");
    if(scanf("%d", &a) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj b:");
    if(scanf("%d", &b) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d", GCD(a, b));
    return 0;
}

