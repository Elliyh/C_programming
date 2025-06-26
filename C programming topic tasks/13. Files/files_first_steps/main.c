#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main( )
{
    char nazwa_zmiennej[31] = {'\0'};
    printf("Podaj sciezke do pliku:\n");
    scanf("%30[^\n]", nazwa_zmiennej);
    FILE *fl = fopen(nazwa_zmiennej, "r");
    if(fl == NULL)
    {
        printf("Couldn't open file");
        return 4;
    }
    char c;
    int size = 0;
    c = fgetc(fl);
    while(c != EOF)
    {
        printf("%c", c);
        c = fgetc(fl);
        size++;
    }
    if (size == 0)
        printf("Nothing to show\n");
    fclose(fl);
    return 0;
}

