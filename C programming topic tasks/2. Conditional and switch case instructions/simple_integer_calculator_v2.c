#include <stdio.h>

int main() {
    int x, y;
    printf("Wprowadz x\n");
    if (scanf("%d", &x) == 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Wprowadz y\n");
    if (scanf("%d", &y) == 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("suma = %d\n", x+y);
    printf("roznica = %d\n", x-y);
    printf("iloczyn = %d\n", x*y);
    if (y != 0)
        printf("iloraz = %d\n", x/y);
    else
        printf("Operation not permitted\n");
    return 0;
}
