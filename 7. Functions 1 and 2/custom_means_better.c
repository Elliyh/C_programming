#include <stdio.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

unsigned int my_strlen(const char tab[])
{
    if (tab[0] == '\0')
    {
        return 0;
    }
    int pointer = 0, i;
    for (i = 0; tab[i] != '\0'; i++)
    {
        if(tab[i] == '\0')
        {
            return pointer;
        }
        if (tab[i] == '\\')
        {
            continue;
        }
        pointer += 1;
    }
    return pointer;
}

int my_atoi(const char tab[])
{
    int pointer = 0;
    int i = 0, sum = 0;
    for (i = 0; tab[i] != '\0'; i++)
    {
        if ((tab[i]< '0' || tab[i]> '9') && tab[i] != '.' && tab[i] != '-')
        {
            break;
        }
        if (tab[i] == '.')
        {
            break;
        }
    }
    i--;
    for (i = i; i >= 0; i--)
    {
        if ((tab[i]< '0' || tab[i]> '9') && tab[i] != '.' && tab[i] != '-')
        {
            return 0;
        }
        if (tab[i] == '-')
        {
            sum *= -1;
            break;
        }

        if (tab[i] <= '9' && tab[i] >= '0')
        {
            sum += (pow(10, pointer)*(tab[i]-48));
            pointer += 1;
        }
    }
    return sum;
}
float my_atof(const char tab[])
{
    float sum = (float)my_atoi(tab);
    int pointer = 0;
    float vremeno = 0.100000;
    for (int i = 0; tab[i] != '\0'; i++)
    {
        /*if ((tab[i]< '0' || tab[i]> '9') && tab[i] != '.' && tab[i] != '-')
        {
            return 0;
        }*/
        if (tab[i] == '.')
        {
            pointer += 1;
            continue;
        }
        if (pointer >= 1)
        {
            if (tab[i]< '0' || tab[i]> '9')
            {
                continue;
            }
            if (sum>=0)
            {
                sum += vremeno * (float)(tab[i] - 48);
                vremeno *= 0.100000;
            }
            else
            {
                sum -= vremeno * (float)(tab[i] - 48);
                vremeno = vremeno * 0.100000;
            }
            pointer += 1;
        }
    }
    return sum;
}


int main() {
    char massive [16];
    printf("podaj liczbe:");
    int i;
    for (i = 0; i < 15; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == '\n')
        {
            massive[i] = '\0';
            break;
        }
    }
    massive[16] = '\0';
    //printf("%d\n", my_strlen("\"The production of too many useful things results in too many useless people. \" - Karl Marx\nThis is the whole point of technology. It creates an appetite for immortality on the one hand. It threatens universal extinction on the other. Technology is lust removed from nature.-Don DeLillo\n"));
    printf("%d\n", my_strlen(massive));
    printf("%d\n", my_atoi(massive));
    printf("%.4f\n", my_atof(massive));
    return 0;

}

