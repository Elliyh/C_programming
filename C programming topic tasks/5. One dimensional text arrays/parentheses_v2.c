#include <stdio.h>

int main() {
    printf("Podaj wyrazenie nawiasowe:\n");
    char massive [50];
    int i, proverka = 1;
    int kol_n = 0, kol_k = 0;
    for (i = 0; i < 50; i++)
    {
        scanf("%c", &massive[i]);

        if (massive[i] == '(')
        {
            kol_n += 1;
        }
        else if (massive[i] == ')')
        {
            kol_k += 1;
        }
        else if (massive[i] == '\n')
        {
            break;
        }


        if ((i == 49 && kol_n != kol_k) || (massive[i] == '\n' && kol_n != kol_k))
        {
            proverka = 0;
            break;
        }


    }

    kol_n = 0, kol_k = 0;

    for (int j = 0; j <= i; j++)
    {
        if (massive[j] == '(')
        {
            kol_n += 1;
        }
        else if (massive[j] == ')')
        {
            kol_k += 1;
        }

        if ((j == 49 && kol_n != kol_k) || (massive[j] == '\n' && kol_n != kol_k))
        {
            proverka = 0;
            break;
        }

        if (massive[j+1] == '\n')
        {
            if (kol_n != kol_k)
                proverka = 0;
            break;
        }

        if (massive[j] == ')' && massive[j+1] == '(')
        {
            if (kol_k > kol_n)
            {
                proverka = 0;
            }
        }
    }


    if (proverka)
        printf("Poprawny");
    else
        printf("Niepoprawny");

    return 0;
}
