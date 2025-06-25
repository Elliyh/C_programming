#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned long long my_atol_rec(const char tab[], int size)
{
    if (size == 0 || (tab[size-1] < '0' || tab[size-1] > '9'))
        return 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] < '0' || tab[i] > '9')
            return 0;
    }
    return (my_atol_rec(tab, size - 1) * 10) + (tab[size - 1] - '0');
}


//1
int main() {
    printf("podaj liczbe:");
    int i;
    char massive[15];
    for (i = 0; i < 15; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == '\n')
            break;
        if (massive[i] < '0' || massive[i] > '9')
        {
            printf("Incorrect input");
            return 1;
        }
    }
    printf("%lld\n", my_atol_rec(massive, i));
    return 0;
}

