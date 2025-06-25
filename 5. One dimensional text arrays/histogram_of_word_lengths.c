#include <stdio.h>

int main() {
    char massiv[1000] = {0};
    char massiv2[1000] = {0};
    printf("Podaj tekst:\n");
    int i, new_pointer = 0;

    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massiv[i]);
        if (massiv[i] == '\n')
        {
            break;
        }
        if ((massiv[i] >= 65 && massiv[i] <= 90) || (massiv[i] >= 97 && massiv[i] <= 122))
        {
            massiv2[new_pointer] = massiv[i];
            new_pointer += 1;
        }
        else
        {
            if (new_pointer != 0)
            {
                if (massiv2[new_pointer - 1] != ' ')
                {
                    massiv2[new_pointer] = ' ';
                    new_pointer += 1;
                }
                else if (massiv2[new_pointer - 1] == ' ')
                {
                    continue; // mozno ubrat
                }
            }
        }

    }
    int massiv_int [1000][2];
    for (int j = 1; j < 1001; j++)
    {
        massiv_int[j-1][0] = j;//  0 0 = 1,  1 0 = 2
        massiv_int[j-1][1] = 0;
    }

    int nacialo = 0, koniec = 0;
    for (int j = 0; j < 1000; j++)
    {
        if (massiv2[j] == 32 || massiv[j] == '\n' || j == 999 || massiv2[j] == 0)
        {
            koniec = j;
            massiv_int[(nacialo == 0 ) ? (koniec - nacialo) - 1 : (koniec - nacialo) - 2][1] += 1;
            nacialo = koniec;
            if (massiv[j] == '\n' || massiv[j] == 0)
                break;
        }
    }
    for (int j = 0; j < 1000; j++)
    {
        if (massiv_int[j][1] != 0)
        {
            printf("%d - %d\n", massiv_int[j][0], massiv_int[j][1]);
        }
    }
    return 0;
}
