#include <stdio.h>

int main() {
    printf("podaj liczby:\n");
    int in_p= 0, in_n = 0;
    int proverka = 0, par = 0;
    int masiv[10]= {0}, masiv_par [4] = {0}, masiv_nepar[6] = {0};
    for (int i = 0; i < 10; i++)
    {
        if (scanf("%d", &masiv[i]))
        {
            proverka += 1;
            if (masiv[i]%2 == 0)
            {
                par += 1;
            }
        }
    }
    if (proverka != 10)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (par != 4)
    {
        printf("Incorrect input data");
        return 2;
    }
    for (int j = 0; j < 10; j++)
    {
        if (masiv[j]%2 == 0)
        {
            masiv_par[in_p] = masiv[j];
            in_p += 1;
        }
        else
        {
            masiv_nepar[in_n] = masiv[j];
            in_n += 1;
        }

    }
    in_p = 0; in_n = 0;
    for (int g = 0; g < 10; g++)
    {
        if (g == 0 || g == 3 || g == 6 || g == 9)
        {
            printf("%d ", masiv_par[in_p]);
            in_p += 1;
        }
        else
        {
            printf("%d ", masiv_nepar[in_n]);
            in_n += 1;
        }
    }
    return 0;
}
