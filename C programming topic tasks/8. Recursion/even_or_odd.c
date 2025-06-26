#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int even_odd(int s, int n)
{
    if(n < 0)
    {
        return -1;
    }
    else if (n == 0)
    {
        return s;
    }

    if(s % 2 == 0)
    {
        return even_odd(s/2, n-1);
    }
    return even_odd(3*s+1,n-1);

}




int main() {
    int s, n;
    printf("Podaj wartosc pierwszego wyrazu:");
    if (scanf("%d", &s) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj numer wyrazu, którego wartość chcesz wyznaczyc:");
    if (scanf("%d", &n) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    if (n < 0)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Wynik: %d", even_odd(s, n));
    return 0;
}

