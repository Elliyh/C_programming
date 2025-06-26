#include <stdio.h>

int main() {
    int masiv1 [100] = {0}, masiv2[100] = {0};
    int proverka = 0;
    char nul;
    int i;
    printf("podaj liczby:\n");
    for (i = 0; i < 100; i++)
    {
        if ((scanf("%d", &masiv1[i]) == 1 ))
        {
            nul = getchar();

            if (masiv1[i] == 0 && nul == '\n' && i == 0) {
                //proverka += 1;
                //printf("not enough data available");
                //return 2;
                break;
            }
            if (masiv1[i] == 0 && nul == '\n' && i > 0)
                break;

        }
        else
            proverka += 1;
    }

    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    if (i > 99)
    {
        int a;
        while ((a = getchar()) != '\n') {
        }
    }


    printf("podaj liczby:\n");

    int proverka1 = 0;
    for (int j = 0; j < 100; j++)
    {
        if ((scanf("%d", &masiv2[j]) == 1 ))
        {
            nul = getchar();

            if (masiv2[j] == 0 && nul == '\n' && j == 0) {
                //proverka1 += 1;
                //printf("not enough data available");
                //return 2;
                break;
            }
            if (masiv2[j] == 0 && nul == '\n' && j > 0)
                break;

        }
        else
            proverka1 += 1;
    }


    if (proverka1 != 0)
    {
        printf("Incorrect input");
        return 1;
    }

    if (masiv1[0] == 0 || masiv1[1] == 0 || masiv2[0] == 0)
    {
        printf("not enough data available");
        return 2;
    }

    int j = 0;
    while (masiv1[j+1] != 0 && j < 99)
    {
        int start = (masiv1[j] < masiv1[j+1]) ? masiv1[j] : masiv1[j+1];
        int end = (masiv1[j] > masiv1[j+1]) ? masiv1[j] : masiv1[j+1];
        int kol_elementov_predel = 0;
        for (int k = 0; masiv2[k] != 0 && k < 100; k++)
        {
            if (start < masiv2[k] && end > masiv2[k])
            {
                kol_elementov_predel += 1;
            }
        }
        printf("%d ", kol_elementov_predel);
        j += 1;
    }




    return 0;
}