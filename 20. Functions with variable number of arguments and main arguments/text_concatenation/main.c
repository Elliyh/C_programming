#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int concatenate(char* buffor, int size, int count, ...)
{
    if(count <= 0 || size<=0 || buffor == NULL)
    {
        return 1;
    }

    va_list current_text;
    va_start(current_text, count);
    int len = 0;
    for(int i = 0; i < count; i++)
    {
        char* temp = va_arg(current_text, char*);
        if(temp)
            len += (int)strlen(temp);
    }
    va_end(current_text);
    len += count;
    if(len > size)
        return 2;
    int i = 0;
    while(*(buffor+i))
    {
        *(buffor+i) = '\0';
        i++;
    }
    va_start(current_text, count);
    for(i = 0; i < count; i++)
    {
        char* temp = va_arg(current_text, char*);
        strcat(buffor, temp);
        if(i+1 < count)
            strcat(buffor, " ");
    }
    strcat(buffor, "\0");
    return 0;
}

int main() {
    char** text_list = calloc(4, sizeof(char*));
    if(text_list == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for(int i = 0; i < 4; i++) {
        *(text_list + i) = calloc(1001, sizeof(char));
        if (*(text_list + i) == NULL) {
            for (int g = i - 1; g >= 0; g--) {
                free(*(text_list + g));
            }
            free(text_list);
            printf("Failed to allocate memory");
            return 8;
        }
        for(int j = 0; j < 1001; j++)
            *(*(text_list+i)+j) = '\0';
    }
    char* buffor = calloc(4004, sizeof(char));
    if(buffor == NULL)
    {
        for(int i = 0; i < 4; i++)
        {
            free(*(text_list+i));
        }
        free(text_list);
        printf("Failed to allocate memory");
        return 8;
    }
    printf("Podaj liczbe tekstow do wprowadzenia:");
    int count_text = 0;
    if(!scanf("%d", &count_text))
    {
        for(int i = 0; i < 4; i++)
        {
            free(*(text_list+i));
        }
        free(text_list);
        free(buffor);
        printf("Incorrect input");
        return 1;
    }
    if (count_text > 4 || count_text < 2) {
        for(int i = 0; i < 4; i++)
        {
            free(*(text_list+i));
        }
        free(text_list);
        free(buffor);
        printf("Incorrect input data");
        return 2;
    }
    while(getchar() != '\n');
    printf("Podaj tekst: ");
    for(int i = 0; i < count_text; i++)
    {
        scanf("%1000[^\n]", *(text_list+i));
        while(getchar() != '\n');
    }
    /*int len = 0;
    for(int i = 0; i < count_text; i++)
    {
        len += (int)strlen(*(text_list+i));
    }
    len+= count_text;
    char* buffor = calloc(len, sizeof(char));
    if(buffor == NULL)
    {
        for(int i = 0; i < 4; i++)
        {
            free(*(text_list+i));
        }
        free(text_list);
        printf("Failed to allocate memory");
        return 8;
    }*/
    int spraw = concatenate(buffor, 4004, count_text, *(text_list+0), *(text_list+1), count_text >= 3 ? *(text_list+2) : NULL, count_text == 4 ? *(text_list+3) : NULL);
    if(spraw != 0)
    {
        for(int i = 0; i < 4; i++)
        {
            free(*(text_list+i));
        }
        free(text_list);
        free(buffor);
        printf("Incorrect input data");
        return 8;
    }
    printf("%s", buffor);
    free(buffor);
    for(int i = 0; i < 4; i++)
    {
        free(*(text_list+i));
    }
    free(text_list);
    return 0;
}

/*
There may be times when we are powerless to prevent injustice, but there must never be a time when we fail to protest. - Elie Wiesel
One of the interesting applications of symbolic systems is artificial intelligence, and I spent some time thinking about how to create a brain that operates the way ours does. - Marissa Mayer
Sometimes you wake up. Sometimes the fall kills you. And sometimes, when you fall, you fly. - Neil Gaiman
Do one thing every day that scares you. - Eleanor Roosevelt
 */



