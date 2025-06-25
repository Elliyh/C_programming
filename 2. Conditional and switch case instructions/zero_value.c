#include <stdio.h>

int main() {
    printf("Podaj liczbe:");
    int cislo;
    if (scanf("%d", &cislo))
    {}
    else
    {
        printf("Incorrect input");
        return 1;
    }
    if (cislo)
    {
        printf("Not equal to zero");
    }
    else printf("Equal to zero");
    return 0;
}
