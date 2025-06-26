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
    else if (i == -1)
    {
        printf("not enough data available");
        return 2;
    }
    int a;
    while ((a = getchar()) != '\n'){}
    int dodat;
    printf("Podaj dodatkową liczbę:");
    if (scanf("%d", &dodat) != 1)
    {
        printf("incorrect input");
        return 1;
    }
    int m = 0, w = 0;
    for (int j = 0; j <= i; j++)
    {
        if (masiv[j] < dodat)
        {
            m += 1;
        }
        else if (masiv[j] > dodat)
        {
            w += 1;
        }
    }
    printf("%d\n%d", m, w);
}
