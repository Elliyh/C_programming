#include <stdio.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    char nazwa_zmiennej[51] = {'\0'};
    printf("Podaj nazwe pliku:");
    scanf("%30s", nazwa_zmiennej);
    while (getchar()!= '\n'){}
    int size_name = strlen(nazwa_zmiennej);
    if (size_name + 5 > 50)
    {
        printf("couldn't create file");
        return 5;
    }
    if (*(nazwa_zmiennej+size_name-1) != 'p' || *(nazwa_zmiennej+size_name-2) != 'm' || *(nazwa_zmiennej+size_name-3) != 'b' || *(nazwa_zmiennej+size_name-4) != '.')
    {
        printf("Unsupported File Format");
        return 7;
    }
    FILE *origin = fopen(nazwa_zmiennej, "rb");
    for (int i = size_name; i >= 0; --i) {
        *(nazwa_zmiennej+i + 5) = *(nazwa_zmiennej+i);
    }
    *(nazwa_zmiennej) = 'c';
    *(nazwa_zmiennej + 1) = 'o';
    *(nazwa_zmiennej + 2) = 'p';
    *(nazwa_zmiennej + 3)=  'y';
    *(nazwa_zmiennej + 4) = '_';


    if (origin == NULL)
    {
        printf("couldn't open file");
        return 4;
    }

    FILE *copy = fopen(nazwa_zmiennej, "wb");

    if(copy == NULL)
    {
        fclose(origin);
        printf("couldn't create file");
        return 5;
    }


    int check;
    while ((check = fgetc(origin)) != -1) {
        if (check == EOF)
        {
            break;
        }
        fputc(check, copy);
    }
    fclose(origin);
    fclose(copy);
    printf("File saved");
    return 0;
}


