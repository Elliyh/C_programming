#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"



int my_strlen(const char* str)
{
    if(str == NULL)
    {
        return -1;
    }

    int i = 0;
    while(*(str+i) != '\0')
    {
        i++;
    }
    return i;
}


char* my_strcpy(char* dest, const char* src)
{
    if (dest == NULL || src == NULL)
    {
        return NULL;
    }

    int i = 0;
    while (*(src+i) != '\0')
    {
        *(dest+i) = *(src+i);
        i++;
    }
    *(dest+i) = '\0';
    return dest;
}


char* my_strcat(char* dest, const char* src)
{
    if (dest == NULL || src == NULL)//|| (my_strlen(dest)+my_strlen(src) > 1000)
    {
        return NULL;
    }

    /*if (*dest == '\0')
    {
        return dest;
    }*/

    int i = my_strlen(dest);
    int g = 0;
    while (*(src+g)!= '\0')
    {
        *(dest+i) = *(src+g);
        i++;
        g++;
    }
    *(dest+i) = '\0';
    return dest;
}


int main() {
    char txt1 [10000] = {'\0'};
    char txt2 [10000] = {'\0'};
    char* ukaz_txt1 = txt1;
    char* ukaz_txt2 = txt2;
    printf("Wprowadz napis pierwszy:");
    scanf("%1000[^\n]", txt1);
    while(getchar()!='\n'){}
    printf("Wprowadz napis drugi:");
    scanf("%1000[^\n]", txt2);
    while(getchar()!='\n'){}
    int len1 = my_strlen(ukaz_txt1);
    int len2 = my_strlen(ukaz_txt2);
    printf("dlugosc:%d dlugosc:%d\n", len1, len2);
    my_strcat(txt2, txt1);
    printf("%s\n", txt2);
    my_strcpy(txt2, txt1);
    printf("%s", txt2);

    return 0;
}

