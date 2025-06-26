#include <stdio.h>

int main() {
    char *massiv[]= {"zero", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec", "dziesiec"};
    int liczba;
    printf("Podaj liczbe z zakresu 0-10:");
    if (scanf("%d", &liczba) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else{
        if (liczba < 0 || liczba > 10)
        {
            printf(" Incorrect input data");
            return 2;
        }
        else
            printf("%s", massiv[liczba]);
    }
    return 0;
}
