#include <stdio.h>
#include <ctype.h>

int main() {
    char massiv[1000] = {0};
    int massiv_int [1001] = {0};
    int ilosc_glas = 0;
    printf("Podaj tekst:\n");
    int i;
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massiv[i]);
        if (massiv[i] == '\n' || i == 999)
        {
            if (massiv[i-1] != ' ')
            {
                massiv[i] = tolower(massiv[i]);
                if (massiv[i] == 97 || massiv[i] == 101 || massiv[i] == 105 || massiv[i] == 111 || massiv[i] ==  117
                    || massiv[i] == 121)
                {
                    ilosc_glas += 1;
                }
                massiv_int[ilosc_glas] += 1;
            }


            break;

        }
        if ((massiv[i] >= 65 && massiv[i] <= 90) || (massiv[i] >= 97 && massiv[i] <= 122))
        {
            massiv[i] = tolower(massiv[i]);
            if (massiv[i] == 97 || massiv[i] == 101 || massiv[i] == 105 || massiv[i] == 111 || massiv[i] ==  117
             || massiv[i] == 121)
            {
                ilosc_glas += 1;
            }
        }
        else
        {
            massiv_int[ilosc_glas] += 1;
            ilosc_glas = 0;
        }
    }

    for (int j = 0; j < 1001; j++)
    {
        if (massiv_int[j] != 0)
        {
            printf("%d - %d\n", j, massiv_int[j]);
        }

    }

}