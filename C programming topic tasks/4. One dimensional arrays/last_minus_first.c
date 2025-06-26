#include <stdio.h>

int main() {
    int masiv [1000] = {0};
    printf("Podaj liczby:");
    int proverka = 0;
    int i;
    for (i = 0; i < 1000; i++)
    {
        if (scanf("%d", &masiv[i]) != 1)
        {
            proverka += 1;
        }
        if (masiv[i] == 0)
        {
            i-= 1;
            break;
        }
    }
    if (i == 1000)
        i-=1;
    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (i == -1 || i == 0)
    {
        printf("not enough data available");
        return 2;
    }

    for (int j = 0; i > j || i == j; j++, i--)
    {
        if (i==j)
        {
            printf("%d ", masiv[j]);
            break;
        }
        printf("%d ", masiv[i]-masiv[j]);
    }


    return 0;
}
