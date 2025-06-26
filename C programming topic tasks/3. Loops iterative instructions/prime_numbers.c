#include <stdio.h>
#include <math.h>

char *proverka(int liczba)
{
    if (liczba <= 1)
        return "NO";
    else if (liczba % 2 == 0 && liczba != 2)
        return "NO";
    int max = (int)sqrt(liczba);
    for (int i = 3; i <= max; i += 2)
    {
        if (liczba%i == 0)
            return "No";
    }
    return "YES";
}

int main() {
    printf("Podaj liczbe:");
    int liczba;
    if (scanf("%d", &liczba))
    {
        printf("%s", proverka(liczba));
    }
    else
    {printf("incorrect input");
        return 1;}
    return 0;

}
