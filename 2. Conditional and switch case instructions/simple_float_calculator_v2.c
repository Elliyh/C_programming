#include <stdio.h>

int main() {
    float x, y;
    printf("Podaj pierwsza liczbe:\n");
    if (scanf("%f", &x) == 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj druga liczbe:\n");
    if (scanf("%f", &y) == 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("suma = %f\n", x+y);
    printf("roznica = %f\n", x-y);
    printf("iloczyn = %f\n", x*y);
    if (y != 0)
        printf("iloraz = %f\n", x/y);
    else
        printf("Operation not permitted\n");
    return 0;
}