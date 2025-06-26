#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Podaj tekst:\n");
    int i;
    char massive [1000];
    int symb = 0;
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == '\n')
        {
            break;
        }
        if (massive[i] >= 'A' && massive[i] <= 'Z')
        {
            massive[i] = tolower(massive[i]);
        }

    }
    int g = 0;
    for (int j = 0; j < i; j++)
    {
        if (massive[j+1] == '\n' || j == 999)
        {
            if (g > 0)
            {
                symb += 1;
            }
            break;
        }

        if (massive[j]< 'a' || massive[j] > 'z')
        {
            if (g > 0)
            {
                symb += 1;
                g = 0;
            }

        }

        if (((massive[j] == 97 || massive[j] == 101 || massive[j] == 105 || massive[j] == 111 || massive[j] ==  117
                || massive[j] == 121)) && ((massive[j+1] == 97 || massive[j+1] == 101 || massive[j+1] == 105 ||
                massive[j+1] == 111 || massive[j+1] ==  117 || massive[j+1] == 121)))
        {
            g += 1;
        }
    }

    printf("%d", symb);
    return 0;
}
