#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int is_balanced(unsigned long long a)
{

    int par = 0, nepar = 0;
    unsigned long long i;
    for (i = 1; i <= a; i++)
    {
        if (i%2 == 1 && a % i == 0)
            nepar++;
        if (i%2 == 0 && a % i == 0)
            par++;
    }
    if (par==nepar)
        return 1;
    else
        return 0;
}


int main() {
    printf("Podaj liczbe:");
    unsigned long long int a = 1000;
    if(!scanf("%llu", &a))
    {
        printf("Incorrect input");
        return 1;
    }
    if (a > 100000000000000)
    {
        printf("Incorrect input");
        return 1;
    }
    a++;
    while(is_balanced(a) != 1)
    {
        a++;
    }
    printf("%llu", a);

    return 0;
}

