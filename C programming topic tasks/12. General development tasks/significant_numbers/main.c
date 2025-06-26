#include <stdio.h>
#include <math.h>

int prow(int a)
{
    int i;
    int sum = 0, il = 0;
    for (i = 1; i < a; i++)
    {
        if (a%i == 0)
        {
            sum += i;
            il++;
        }
    }
    if ((float)sum/(float)il < sqrt(a))
        return 1;
    else
        return 0;
}

int main() {
    int start, stop;
    printf("Podaj poczatek:");
    if(!scanf("%d", &start))
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj koniec:");
    if(!scanf("%d", &stop))
    {
        printf("Incorrect input");
        return 1;
    }
    if (start >= stop || start < 0 || stop < 0)
    {
        printf("Incorrect input data");
        return 2;
    }
    int i, il = 0;
    for (i = start; i <= stop; i++)
    {
        il += prow(i);
    }
    printf("%d", il);


    return 0;
}
