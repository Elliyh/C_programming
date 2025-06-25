#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int swap(char *a, char *b)
{
    if (a == NULL || b == NULL)
    {
        return 1;
    }
    char temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

char* reverse(char* text)
{
    if (text == NULL)
    {
        return NULL;
    }

    char* pocz = text;
    char* kon = text;

    while (*kon != '\0')
    {
        kon++;
    }
    kon--;

    while(kon > pocz)
    {
        swap(pocz, kon);
        pocz++;
        kon--;
    }
    return text;

}


char* remove_non_letters(char* text)
{

    if (text == NULL)
    {
        return NULL;
    }
    char* wskaz = text;
    while (*wskaz != '\0')
    {
        if (!(('A' <= *wskaz && *wskaz <= 'Z') || ('a' <= *wskaz && *wskaz <= 'z')))
        {
            *wskaz = ' ';
        }
        wskaz++;
    }
    return text;
}


char* trim(char* text)
{
    if (text == NULL)
    {
        return NULL;
    }
    if (*text == '\0')
    {
        return text;
    }
    char* wskaz = text;

    while(*(wskaz+1) != '\0')
    {
        while ((*wskaz == ' ' && *(wskaz+1) == ' ') )
        {
            char* new_wskaz = wskaz;
            while(*(new_wskaz+1) != '\0')
            {
                swap(new_wskaz, new_wskaz+1);
                new_wskaz++;
            }
            *new_wskaz = '\0';
        }
        wskaz++;
    }
    while (*text == ' ')
    {
        char* new_wskaz = text;
        while(*(new_wskaz+1) != '\0')
        {
            swap(new_wskaz, new_wskaz+1);
            new_wskaz++;
        }
    }

    char* kon = text;

    while (*kon != '\0')
    {
        kon++;
    }
    while (*(kon-1) == ' ')
    {
        *(kon-1) = '\0';
        kon--;
    }



    return text;
}

int main() {
    printf("Podaj tekst:");
    char tekst [1001];
    for (int i = 0; i < 1001; i++)
    {
        *(tekst+i) = '\0';
    }
    scanf("%1000[^\n]", tekst);
    remove_non_letters(tekst);
    reverse(tekst);
    if (*tekst == 32 && *(tekst+1) == 32 && *(tekst+2) == 32)
    {
        printf("wohs ot gnihtoN");
        return 0;
    }
    trim(tekst);

    printf("%s", tekst);

    return 0;
}

