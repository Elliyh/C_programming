#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    for (int i = 1; i <= 10; i++)
    {
        int liczba = ((rand() % 11) ) + 30;
        printf("%d ", liczba);
    }
    return 0;
}
