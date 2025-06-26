#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"





int file_size_from_file(FILE *f)
{
    if (f == NULL)
        return -2;
    int size = 0;
    char c;
    int pos = ftell(f);

    fseek(f, 0, SEEK_SET);
    c = fgetc(f);
    while (c != EOF)
    {
        size += sizeof(c);
        c = fgetc(f);
    }

    //if (size == 0)
        //return -1;
    fseek(f, pos, SEEK_SET);
    return size;
}


int file_size_from_path(const char *path)
{
    if (path == NULL)
    {
        return -2;
    }
    FILE *f = fopen(path, "r");
    if (f == NULL)
        return -1;
    fseek(f, 0, SEEK_SET);
    int size = file_size_from_file(f);
    fclose(f);
    return size;
}

int main() {
    char nazwa_zmiennej[31] = {"\n"};
    printf("Podaj sciezke do pliku:");
    scanf("%30[^\n]", nazwa_zmiennej);
    FILE *f = fopen(nazwa_zmiennej, "r");
    if (f == NULL)
    {
        printf("couldn't open file");
        //fclose(f);
        return 4;
    }
    int size1 = file_size_from_file(f);
    int size2 = file_size_from_path(nazwa_zmiennej);
    if (size1 != size2 || size1 == -2 || size2 == -2)
    {
        printf("couldn't open file");
        fclose(f);
        return 4;
    }
    fclose(f);
    printf("Rozmiar pliku wynosi %d bajtów", size1);
    return 0;
}

