#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int liczba = (rand() % 100) + 1;
    for (int i = 1; i <= 10; i++)
    {
        printf("Zgadnij:");
        int ug = 0;
        scanf("%d", &ug);
        if (ug == liczba) {
            printf("wygrales");
            return 0;
        }
        else if (ug > liczba)
            printf("za duzo\n");
        else if (ug < liczba)
            printf("za malo\n");

    }
    printf("przegrales");
    return 0;
}
