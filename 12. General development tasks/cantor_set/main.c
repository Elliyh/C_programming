#include <stdio.h>

void zamiana(char* massive, int start, int stop, int licznik)
{
    licznik = licznik/3;
    for (int i = start+licznik; i < stop-licznik; i++)
    {
        massive[i] = ' ';
    }
    return;
}


int main() {
    printf("Podaj glebokosc:");
    int krok, licznik, i;
    if (!scanf("%d", &krok))
    {
        printf("Incorrect input");
        return 1;
    }
    if (krok < 1 || krok > 6)
    {
        printf("Incorrect input data");
        return 2;
    }
    int il = 1;
    for (int g = 0; g < krok-1; g++)
    {
        il *= 3;
    }
    char massive [731] = {'\0'};
    for (i = 0; i < il; i++)
    {
        massive[i] = '_';
    }
    massive[i] = '\0';
    massive[i+1] = '\0';

    int start = 0, stop = 0;

    printf("%s", massive);
    for (i = 0; i < krok-1; i++)
    {
        licznik = 0;
        start = 0;
        stop = 0;
        while(stop<il+1)
        {
                if ((massive[stop] == ' ' || massive[stop] == '\0') && licznik > 0 && licznik != 1)
            {
                zamiana(massive, start, stop, licznik);
                licznik = 0;
                while (massive[stop] != '_' && massive[stop] != '\0')
                {
                    stop++;
                }
                start = stop;
                stop++;
                if (massive[stop] == '_')
                {
                    licznik++;
                };
                continue;
            }
            if (massive[stop] == '_')
            {
                licznik++;
            }
            stop++;
        }
        printf("\n%s", massive);
    }

    return 0;
}
