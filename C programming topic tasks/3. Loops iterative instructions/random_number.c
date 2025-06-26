#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int liczba = (rand() %100) + 1;
    printf("%d", liczba);
    return 0;
}
