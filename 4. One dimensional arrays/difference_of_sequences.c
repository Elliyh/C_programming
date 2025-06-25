#include <stdio.h>

int main() {
    int masiv [100] = {0};
    printf("Podaj liczby:");
    int proverka = 0;
    int i;
    for (i = 0; i < 100; i++)
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
    if (i == 100)
        i-=1;
    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    int a;
    while ((a = getchar()) != '\n'){}
    int masiv1 [100] = {0};
    printf("Podaj liczby:");
    proverka = 0;
    int j;
    for (j = 0; j < 100; j++)
    {
        if (scanf("%d", &masiv1[j]) != 1)
        {
            proverka += 1;
        }
        if (masiv1[j] == 0)
        {
            j-= 1;
            break;
        }
    }
    if (j == 100)
        j-=1;
    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (j == -1)
    {
        printf("not enough data available");
        return 2;
    }
    else if (i == -1)
    {
        printf("not enough data available");
        return 2;
    }
    int b;
    while ((b = getchar()) != '\n'){}
    int predel = (i<j) ? i : j;
    for (int g = 0; g <= predel; g++)
    {
        printf("%d ", masiv[g]-masiv1[g]);
    }


    return 0;
}
