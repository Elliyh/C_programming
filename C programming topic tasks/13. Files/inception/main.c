#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int read_file(const char *filename)
{
    if(filename == NULL)
        return -1;
    int count_files = 1;
    FILE *f = fopen(filename, "r");
    if (f == NULL)
    {
        return 0;
    }


    char *ptr = malloc(31 * sizeof(char));
    int prov = fscanf(f, "%30s", ptr);
    while (prov == 1)
    {
        printf("%s\n", ptr);
        count_files += read_file(ptr);
        prov = fscanf(f, "%30s", ptr);
    }
    free(ptr);
    fclose(f);
    return count_files;
}

int main() {
    char *massive = malloc(31 * sizeof(char));
    printf("Podaj sciezke do pliku:\n");

    scanf("%30[^\n]", massive);
    int kol = read_file(massive);
    if (kol == -1 || kol == 0)
    {
        printf("couldn't open file");
        free(massive);
        return 4;
    }
    printf("%d", kol);
    free(massive);
    return 0;
}

