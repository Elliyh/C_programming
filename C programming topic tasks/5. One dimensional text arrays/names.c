#include <stdio.h>

int main() {
    printf("Wpisz swoje imie:\n");
    char massive [30];
    int i;
    for (i = 0; i < 30; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == ' ')
        {
            massive[i] = '\n';
        }
        if (massive[i] == '\n' || i == 29)
        {
            if (massive[i] == '\n')
            {
                massive[i] = '\0';
            }
            break;
        }
    }
    printf("Witaj %s!", massive);
    return 0;
}
