#include <stdio.h>
#include <stdint.h>

union bit_set{
    unsigned int number;
    short two_bytes[2];
    uint8_t bytes[4];
};

int main() {
    printf("Podaj liczbe:");
    union bit_set my_union;
    if(!scanf("%u", &my_union.number))
    {
        printf("Incorrect input");
        return 1;
    }
    printf("%u\n", my_union.number);
    printf("%hu %hu\n", *(my_union.two_bytes), *(my_union.two_bytes+1));
    int i, j;
    for (i = 0; i < 4; i++)
    {
        printf("%d ", *(my_union.bytes+i));
    }
    printf("\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 128; j > 0; j /= 2) {
            printf("%d", (*(my_union.bytes+i) / j) % 2);
        }
        printf(" ");
    }
    return 0;
}
