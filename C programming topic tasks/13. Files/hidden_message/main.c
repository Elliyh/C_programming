#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int lenght(FILE* plik, int mod)
{
    int i = 0;
    char c;
    fseek(plik, 0, SEEK_SET);
    if (mod == 0)
    {
        while (c != '\n')
        {
            c = fgetc(plik);
            i++;
            if ((c < '0' ||  c > '9') && c != ' ' && c != '\n')
                return -2;
        }
    }
    else if (mod == 1)
    {
        while (c != EOF)
        {
            c = fgetc(plik);
            i++;
        }
        i--;
    }
    fseek(plik, 0, SEEK_SET);
    return i;
}



char symbol(char* nazwa, int n)
{
    FILE * plik = fopen(nazwa, "r");
    if (plik == NULL || n < 0 || n >= lenght(plik, 1))
    {
        fclose(plik);
        return -1;
    }

    char c;
    fseek(plik, n , SEEK_SET);
    c = fgetc(plik);
    fclose(plik);
    return c;
}


int show(FILE* f, int n, int size_all, char* nazwa)
{
    fseek(f, 0, SEEK_SET);
    char c;
    c = fgetc(f);
    if (c < '0' || c > '9')
        return 6;
    int i = 0;
    int number = 0;
    fseek(f, 0, SEEK_SET);

    while(i < n)
    {
        c = fgetc(f);
        if (c != ' ' && c != '\n' && (c < '0' || c > '9'))
        {
            return 6;
        }
        if (c == ' ' || c == '\n')
        {
            if (number >= size_all || number < n)
                return 6;
            number = 0;
        }
        else
            number = (number * 10) + (c - '0');
        i++;
    }
    fseek(f, 0, SEEK_SET);
    i = 0;
    number = 0;

    fseek(f, 0, SEEK_SET);
    while(i < n)
    {
        c = fgetc(f);
        if (c == ' ' || c == '\n')
        {
            printf("%c", symbol(nazwa, number));
            number = 0;
        }
        else
            number = (number * 10) + (c - '0');
        i++;
    }
    return 0;
}




int main() {
    char nazwa_zmiennej[31] = {"\n"};
    printf("Podaj sciezke do pliku:");
    scanf("%30[^\n]", nazwa_zmiennej);
    FILE *f = fopen(nazwa_zmiennej, "r");
    if (f == NULL) {
        printf("couldn't open file");
        return 4;
    }
    int size_all = lenght(f, 1);
    int size_numbers = lenght(f, 0);
    if (size_numbers == -2) {
        printf("file corrupted");
        fclose(f);
        return 6;
    }

    int spraw = show(f, size_numbers, size_all, nazwa_zmiennej);
    if (spraw == 6) {
        printf("file corrupted");
        fclose(f);
        return 6;
    }
    fclose(f);
    return 0;
}
