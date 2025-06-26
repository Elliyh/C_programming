#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    printf("Podaj liczbę 64 bitową: ");
    unsigned long long number;
    if (scanf("%llu" SCNd64, &number) != 1) {
        printf("Incorrect input\n");
        return 1;
    }

    for (int i = 63; i >= 0; i--) {
        printf("%llu", (number >> i) & 1);
        if (i % 8 == 0 && i != 0) {
            printf(" ");
        }
    }
    return 0;
}
