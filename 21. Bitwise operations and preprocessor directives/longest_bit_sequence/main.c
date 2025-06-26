#include <stdio.h>
#include <stdint.h>
#include "tested_declarations.h"
#include "rdebug.h"

int longest_series(unsigned int x)
{
    int number = 1;
    int count = 0, max = 0;
    for(int i = 0; i < 32; i++)
    {
        if(x&number)
        {
            count++;
        }
        else
        {
            if (count > max)
                max = count;
            count = 0;
        }
        number <<= 1;
    }
    if (count > max)
        max = count;
    return max;
}


int main() {
    unsigned int liczba;
    printf("Podaj liczbę:");
    if(!scanf("%u", &liczba))
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Wynik: %d", longest_series(liczba));
    return 0;
}

