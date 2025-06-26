#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Podaj tekst:\n");
    char massive[101] = {'\0'}, massive1[1000] = {"\0"};
    int i, sprawd = 0;
    int proverka1 = 0;
    for (i = 0; i < 101; i++)
    {
        scanf("%c", &massive[i]);
        if(massive[i] != '\n' && i == 100)
        {
            proverka1 += 1;
        }
        else if (massive[i] == '\n')
        {
            break;
        }
        if ((massive[i] < 'a' || massive[i] > 'z') && (massive[i] < 'A'
        || massive[i] > 'Z'))
        {
            sprawd += 1;
        }

    }

    if (sprawd != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    if (proverka1)
    {
        printf("Input is too long");
        return 2;
    }


    int poryadok = 0;
    for (int j = 0; j < i; j++)
    {
        if (massive[j] >= 'A' && massive[j] <= 'Z')
        {
            for (int g = 0; g < 3; g++)
            {
                massive1[poryadok] = massive[j];
                poryadok += 1;
            }
        }
        else
        {
            massive1[poryadok] = massive[j];
            poryadok += 1;
        }
    }

    if (poryadok > 200)
    {
        printf("Output is too long");
        return 3;
    }

    for(int f = poryadok-1; f > -1; f--)
    {
        printf("%c", massive1[f]);
    }


    return 0;
}
