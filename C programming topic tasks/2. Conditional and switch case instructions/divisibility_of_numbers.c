#include <stdio.h>

int main() {
    int a, b;
    printf("Podaj pierwszą liczbę całkowitą:");
    if (scanf("%d", &a) != 1)
    {
        printf("Incorrect input");
        return 1;
    };
    printf("Podaj druga liczbę całkowitą:");
    if (scanf("%d", &b) != 1)
    {
        printf("Incorrect input");
        return 1;
    }


    if (b==0)
    {
        printf("Operation not permitted");
        return 1;
    }
    else if (a%b==0)
    {
        printf("%d is divisible by %d", a, b);
    }
    else
        printf("%d is not divisible by %d", a, b);
    return 0;
}