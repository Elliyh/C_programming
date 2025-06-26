#include <stdio.h>

int main() {
    printf("Podaj Imie:\n");
    char massive [10];
    int i;
    for (i = 0; i < 10; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == '\n' || i == 9)
        {
            if (massive[i] == '\n')
                i -= 1;
            break;
        }
    }

    if (massive[i] == 'a')
    {
        printf("Imie zenskie");
    }
    else
    {
        printf("Imie meskie");
    }
    return 0;
}
