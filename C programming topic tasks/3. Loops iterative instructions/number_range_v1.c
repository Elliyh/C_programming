#include <stdio.h>

int main() {
    int min, max;
    printf("Podaj min:");
    if(scanf("%d", &min) == 0)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Podaj max:");
    if(scanf("%d", &max) == 0)
    {
        printf("Incorrect input");
        return 1;
    }
    if ( min > max)
    {
        printf("Incorrect range");
        return 2;
    }
    for (int i = min; i <= max; i++)
        printf("%d ", i);
    return 0;
}
