#include <stdio.h>

int main(){
    char massiv[1000] = {0};
    int i, por, g;
    int max = 0, kol_max = 0;
    int nacialo = 0, koniec = 0, proverka = 0;
    char max_slov [1000][1000];
    printf("Podaj tekst:");
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massiv[i]);
        if ((massiv[i] == 32 && i == 0) || (massiv[i] == 32 && massiv[i+1] == 32))
        {

        }
        if (massiv[i] == '\n')
        {
            koniec = i;
            if ((koniec - nacialo) - 1 == max){

                for (g = nacialo + 1, por = 0; g < koniec; g++, por++)
                {
                    max_slov[kol_max][por] = massiv[g];
                }
                kol_max += 1;
            }


            else if ((koniec - nacialo) - 1 > max)
            {
                max = (koniec - nacialo) - 1;
                if (nacialo == 0)
                {
                    max += 1;
                }
                kol_max = 0;
                for (g = (nacialo == 0) ? nacialo: nacialo + 1, por = 0; g < koniec; g++, por++)
                {
                    max_slov[kol_max][por] = massiv[g];
                }
                kol_max += 1;
            }
            break;
        }
        if ((massiv[i] >= 65 && massiv[i] <= 90) || (massiv[i] >= 97 && massiv[i] <= 122)
        || massiv[i] == 32)
        {
            /*if (koniec == nacialo && max == 1 && massiv[i] != ' ') // && massiv[i] != ' '
            {
                //printf("%d", i);
                max_slov[kol_max][por] = massiv[i];
            }*/
            if (massiv[i] == 32 || i == 999 )
            {
                if ((massiv[i] == 32 && i == 0) || (massiv[i] == 32 && massiv[i+1] == 32))
                {
                    nacialo += 1;
                    continue;
                }
                koniec = i;
                if ((koniec - nacialo) - 1 == max && max != 0)//dobav
                {

                    for (i = (nacialo == 0) ? nacialo: nacialo + 1, por = 0; i < koniec; i++, por++)
                    {
                        max_slov[kol_max][por] = massiv[i];
                    }
                    kol_max += 1;
                }
                else if ((koniec - nacialo) - 1 > max || (max == 0 && (koniec - nacialo) - 1 == 0))
                {
                    max = (koniec - nacialo) - 1;
                    if (nacialo == 0 || i == 999) // dob || i == 999
                    {
                        max += 1;
                    }
                    kol_max = 0;
                    for (g = (nacialo == 0) ? nacialo: nacialo + 1, por = 0; g < ((koniec == 999) ? koniec+1 : koniec); g++, por++) // i = nacialo + 1
                    {
                        max_slov[kol_max][por] = massiv[g];
                    }
                    kol_max += 1;
                }
                nacialo = koniec;
            }
        }
        else
            proverka += 1;


    }
    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%d %d\n", kol_max, max);
    for (int j = kol_max - 1; j >= 0; j--)
    {
        printf("%s\n", max_slov[j]);
    }

    return 0;
}
