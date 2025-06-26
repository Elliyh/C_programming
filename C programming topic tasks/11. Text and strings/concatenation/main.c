#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"



int connect(const char* t1, const char* t2, const char* t3, char* t4, int size)
{
    if (t1 == NULL || t2 == NULL || t3 == NULL || t4 == NULL || size <= 0)
        return 1;
    int spraw = snprintf(NULL, 0, "%s %s %s", t1, t2, t3);
    if (size <= spraw)
    {
        return 1;
    }

    int i = 0, g = 0;
    for (i = 0; *(t1+i) != '\0'; i++) {
        *(t4+g) = *(t1+i);
        g++;
    }
    *(t4+g) = ' ';
    g++;

    for (i = 0; *(t2+i) != '\0'; i++) {
        *(t4+g) = *(t2+i);
        g++;
    }
    *(t4+g) = ' ';
    g++;

    for (i = 0; *(t3+i) != '\0'; i++) {
        *(t4+g) = *(t3+i);
        g++;
    }
    *(t4+g) = '\0';
    return 0;
}



int main() {
    char massive1 [1001];
    char massive2 [1001];
    char massive3 [1001];
    char* t1 =  massive1;
    char* t2 =  massive2;
    char* t3 =  massive3;

    printf("Podaj tekst:\n");
    int i;
    char symbol;
    for(i = 0; i < 1000; i++)
    {
        scanf("%c", &symbol);
        if (symbol == '\n')
        {
            *(t1+i) = '\0';
            break;
        }
        if (i == 0 && symbol == '\n')
        {
            *(t1+i) = '\0';
            break;
        }
        *(t1+i) = symbol;
        if (i == 999 && symbol != '\n')
        {
            *(t1+1000) = '\0';
            while(getchar()!='\n'){}
        }
    }


    printf("Podaj tekst:\n");
    for(i = 0; i < 1000; i++)
    {
        scanf("%c", &symbol);
        if (symbol == '\n')
        {
            *(t2+i) = '\0';
            break;
        }
        if (i == 0 && symbol == '\n')
        {
            *(t2+i) = '\0';
            break;
        }
        *(t2+i) = symbol;
        if (i == 999 && symbol != '\n')
        {
            *(t2+1000) = '\0';
            while(getchar()!='\n'){}
        }
    }

    printf("Podaj tekst:\n");
    for(i = 0; i < 1000; i++) {
        scanf("%c", &symbol);
        if (symbol == '\n') {
            *(t3 + i) = '\0';
            break;
        }
        if (i == 0 && symbol == '\n')
        {
            *(t3+i) = '\0';
            break;
        }
        *(t3+i) = symbol;
        if (i == 999 && symbol != '\n') {
            *(t3 + 1000) = '\0';
            while (getchar() != '\n') {}
        }
    }

    char massive4 [3005];

    char* t4 =  massive4;

    connect(t1, t2, t3, t4, 3005);

    printf("%s", t4);


    return 0;
}

