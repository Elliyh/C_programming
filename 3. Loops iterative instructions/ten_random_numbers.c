#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int liczba = (rand() %100) + 1;
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", liczba);
    }
    return 0;
}
