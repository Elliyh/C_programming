#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool Prost(int x)
{
    if (x % 2 == 0 || x % 3 == 0)
    {
        return false;
    }
    for (int i = 2; i <= (int)sqrt(x); i++)
        if (x % i == 0)
        {
            return false;
        }
    return true;
}


int main() {
    printf("Podaj liczby:\n");
    int masiv [10] = {0};
    int proverka = 0;
    for (int i = 0; i <= 8; i+=2)
    {
        if(scanf("%d %d", &masiv[i], &masiv[i+1]) != 2)
        {
            proverka += 1;
        }
    }
    if (proverka != 0)
    {
        printf("Input data type error");
        return 1;
    }
    for (int j = 0; j < 10; j++)
    {
        printf("%d ", masiv[j]);
        if (masiv[j] == 0 || masiv[j] == 1 || masiv[j] < 0)
        {
            printf("other\n");
        }
        else if (Prost(masiv[j]) || masiv[j] == 2 || masiv[j] == 3)
        {
            printf("prime\n");
        }
        else
        {
            printf("composite\n");
        }

    }

    return 0;
}
