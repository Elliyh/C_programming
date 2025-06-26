#include <stdio.h>
#include "letter_changer.h"
#include "tested_declarations.h"
#include "rdebug.h"

char* change_letter_size(char *txt, enum letter_changer_t c)
{
    if (txt == NULL || (c != TO_LOWER && c != TO_UPPER))
    {
        return NULL;
    }
    int i = 0;
    while(*(txt+i) != '\0')
    {
        if (*(txt+i) == '\0')
            break;
        if (c == TO_UPPER && *(txt+i) >= 'a' && *(txt+i) <= 'z')
        {
            *(txt+i) = to_upper(*(txt+i));
        }
        else if(c == TO_LOWER && *(txt+i) >= 'A' && *(txt+i) <= 'Z')
        {
            *(txt+i) = to_lower(*(txt+i));
        }
        i++;
    }
    return txt;
}

char to_lower(char sym)
{
    if (sym >= 'A' && sym <= 'Z') {
        return sym + ' ';
    }
    return sym;
}
char to_upper(char sym)
{
    if (sym >= 'a' && sym <= 'z') {
        return sym - ' ';
    }
    return sym;
}
