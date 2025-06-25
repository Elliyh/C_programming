#include <stdio.h>

int main() {
    printf("Podaj tekst:\n");
    char massive [1000];
    int massive_int [12] = {0};
    int i;
    for (i = 0; i < 1000; i++)
    {
        scanf("%c", &massive[i]);
        if (massive[i] == '\n')
        {
            break;
        }
        switch(massive[i])
        {
            case 'A':
                massive_int[0] += 1;
                break;
            case 'E':
                massive_int[1] += 1;
                break;
            case 'I':
                massive_int[2] += 1;
                break;
            case 'O':
                massive_int[3] += 1;
                break;
            case 'U':
                massive_int[4] += 1;
                break;
            case 'Y':
                massive_int[5] += 1;
                break;
            case 'a':
                massive_int[6] += 1;
                break;
            case 'e':
                massive_int[7] += 1;
                break;
            case 'i':
                massive_int[8] += 1;
                break;
            case 'o':
                massive_int[9] += 1;
                break;
            case 'u':
                massive_int[10] += 1;
                break;
            case 'y':
                massive_int[11] += 1;
                break;
        }

    }

    int kol_glas = 0;

    for (int j = 0; j < 12; j++)
    {
        if (massive_int[j] != 0)
        {
            kol_glas += 1;
        }
    }

    printf("%d", kol_glas);

    return 0;
}
