#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


char* change_letter_size(char* dest, const char* src)
{
    if (dest == NULL || src == NULL)
    {
        return NULL;
    }
    int i = 0;
    while (*(src+i) != '\0')
    {
        if ((*(src+i) >= 'A' && *(src+i) <= 'Z') || (*(src+i) >= 'a' && *(src+i) <= 'z'))
        {
            if (*(src+i) >= 'A' && *(src+i) <= 'Z')
            {
                *(dest+i) = *(src+i) + ' ';
            }
            else
                *(dest+i) = *(src+i) - ' ';
        }
        else
            *(dest+i) = *(src+i);
        i++;
    }
    *(dest+i) = '\0';
    return dest;
}


int main() {
    printf("Podaj tekst:\n");
    char massive [1001];
    char massive2 [1001];
    char* dest = massive2;
    char* ukaz = massive;
    scanf("%1000[^\n]", ukaz);
    change_letter_size(dest, ukaz);
    printf("%s", dest);

    return 0;
}

