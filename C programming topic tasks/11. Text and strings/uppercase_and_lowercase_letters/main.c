#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int marks_counter(const char* text, int* uppercase, int* lowercase, int* whitespace)
{
    int i = 0;

    if (text == NULL || uppercase == NULL || lowercase == NULL || whitespace == NULL)
        return 1;
    *uppercase = 0, *lowercase = 0, *whitespace = 0;;
    while(*(text+i) != '\0')
    {
        if (*(text+i) <= 'Z' && *(text+i) >= 'A')
        {
            (*uppercase)++;
            i++;
        }
        else if (*(text+i) <= 'z' && *(text+i) >= 'a')
        {
            (*lowercase)++;
            i++;
        }
        else if (*(text+i) == ' ' || *(text+i) == '\t' || *(text+i) == '\n')
        {
            (*whitespace)++;
            i++;
        }
        else
            i++;

    }
    return 0;
}


int main() {
    printf("Podaj tekst:");
    char tekst [1001];
    for (int i = 0; i < 1001; i++)
    {
        *(tekst+i) = '\0';
    }
    scanf("%1000[^\n]", tekst);
    int uppercase = 0, lowercase = 0, whitespace = 0;
    int* ukaz_upper = &uppercase;
    int* ukaz_lower = &lowercase;
    int* ukaz_white = &whitespace;
    char* ukaz_tekst = tekst;
    marks_counter(ukaz_tekst, ukaz_upper, ukaz_lower, ukaz_white);
    printf("%d\n%d\n%d\n", *ukaz_upper, *ukaz_lower, *ukaz_white);
    return 0;
}

