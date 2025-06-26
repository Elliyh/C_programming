#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int sum = 0;
    for (int i = 1; i <= 100; i++)
    {
        int liczba = ((rand() % 11) ) + 10;
        sum += liczba;
    }
    printf("%d", sum);
    return 0;
}
