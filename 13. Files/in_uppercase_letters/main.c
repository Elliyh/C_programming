#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    char nazwa_zmiennej[31];
    printf("Podaj sciezke do pliku:\n");
    scanf("%30s", nazwa_zmiennej);
    FILE *f = fopen(nazwa_zmiennej, "r");
    if (f == NULL)
    {
        printf("COULDN'T OPEN FILE");
        return 4;
    }
    char symbol;
    symbol = fgetc(f);
    if (symbol == EOF)
    {
        printf("NOTHING TO SHOW");
        fclose(f);
        return 0;
    }
    else
    {
        if (symbol <= 'z' && symbol >= 'a')
        {
            symbol = symbol - 'a' + 'A';
        }
        printf("%c", symbol);
        symbol = fgetc(f);
        while (symbol != EOF)
        {
            if (symbol <= 'z' && symbol >= 'a')
            {
                symbol = symbol - 'a' + 'A';
            }
            printf("%c", symbol);
            symbol = fgetc(f);
        }
    }
    fclose(f);
    return 0;

}
