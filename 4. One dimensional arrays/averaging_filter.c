#include <stdio.h>

int main() {
    float masiv [1000] = {0};
    printf("Podaj liczby:");
    int proverka = 0;
    int i;
    for (i = 0; i < 1000; i++)
    {
        if (scanf("%f", &masiv[i]) != 1)
        {
            proverka += 1;
        }
        if (masiv[i] == 0)
        {
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
    else if (i < 2)
    {
        printf("not enough data available");
        return 2;
    }
    for (int j = 0; j < i; j++)
    {
        if (masiv[j+1] == 0)
            break;
        printf("%.2f ", (float)(masiv[j]+masiv[j+1])/2);
    }

    return 0;
}
