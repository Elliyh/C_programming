#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


char* space_changer(char* txt)
{
    if (txt == NULL)
    {
        return NULL;
    }
    int i = 0;
    while(*(txt+i) != '\0')
    {
        if (*(txt+i) == '\0')
            break;
        if (*(txt+i) == ' ')
        {
            *(txt+i) = '_';
        }
        i++;
    }
    return txt;
}


int main() {
    printf("Podaj tekst:");
    char text[1001] = {'\0'};
    char* ukaz_text = text;
    int i;
    char symbol;
    for (i = 0; i < 1000; i++)
    {

        scanf("%c", &symbol);
        if (symbol == '\n')
        {
            *(ukaz_text+i) = '\0';
            break;
        }
        *(ukaz_text + i) = symbol;
    }
    if (i == 1000)
    {
        while(getchar() != '\n'){}
    }
    space_changer(ukaz_text);
    printf("%s", ukaz_text);
    return 0;
}

