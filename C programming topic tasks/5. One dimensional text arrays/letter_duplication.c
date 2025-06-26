#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Podaj tekst:\n");
    char massive[101] = {'\0'}, massive1[1000] = {"\0"};
    int i;
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
            if (massive[i-1] >= '1' && massive[i-1] <= '9')
            {
                printf("Incorrect input");
                return 1;
            }
            break;
        }

    }

    if (proverka1)
    {
        printf("Input is too long");
        return 2;
    }


    int poryadok = 0;
    for (int j = 0; j < i; j++)
    {
        if (j < i-1 && massive[j] >= '1' && massive[j] <= '9' && massive[j+1] >= '1' && massive[j+1] <= '9')
        {
            printf("Incorrect input");
            return 1;
        }
        if (massive[j] >= '1' && massive[j] <= '9')
        {
            for (int g = 0; g < atoi(&massive[j]); g++)
            {
                massive1[poryadok] = massive[j+1];
                poryadok += 1;
            }
            j += 1;
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
