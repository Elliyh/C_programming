#include <stdio.h>
#include <string.h>

int main() {
    printf("podaj liczby:");
    int proverka = 0;
    int masiv [100];
    int i;
    for (i = 0; i < 100; i++)
    {
        if (scanf("%d", &masiv[i]) != 1)
        {
            proverka += 1;
        }
        if (masiv[i] == -1)
        {
            i -= 1;
            break;
        }
    }
    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    if (i < 1)
    {
        printf("not enough data available");
        return 2;
    }
    char vivod [] = "TAK";
    if (i==100)
    {
        i = (sizeof(masiv)/4) - 1;
    }
    for (int j = 0; i >= j; j++, i--)
    {
        if (masiv[j] != masiv[i])
        {
            strcpy(vivod, "NIE");
        }
    }

    printf("%s", vivod);
    return 0;
}
