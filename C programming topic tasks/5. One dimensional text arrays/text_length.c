#include <stdio.h>

int main() {
    printf("Podaj tekst:\n");
    char massive [1000];
    int i;
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == '\n' || i == 999)
        {
            if (i == 999)
            {
                i += 1;
            }
            break;
        }
    }
    printf("%d", i);
    return 0;
}
