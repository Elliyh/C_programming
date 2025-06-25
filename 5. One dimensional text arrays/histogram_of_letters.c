#include <stdio.h>
#include <ctype.h>

int main() {
    printf("Podaj tekst:\n");
    int i;
    char massive [1000];
    int symb [26] = {0};
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massive[i]);
        if (i == 999 || massive[i] == '\n')
        {
            break;
        }

        if (massive[i] >= 'A' && massive[i] <= 'Z')
            massive[i] = tolower(massive[i]);

        if (massive[i] >= 'a' && massive[i] <= 'z')
        {
            symb[massive[i] - 97] += 1;
        }
    }

    for (int j = 0; j < 26; j++)
    {
        printf("%c - %d\n", 97+j, symb[j]);
    }

    return 0;
}
