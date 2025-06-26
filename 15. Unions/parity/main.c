#include <stdio.h>
#include <stdint.h>

union bit_set
{
    unsigned int number;
    uint8_t bytes[4];
};


int main() {
    printf("Podaj wartosc: ");
    union bit_set my_union;
    if(!scanf("%u", &my_union.number))
    {
        printf("Incorrect input");
        return 1;
    }
    int i, j, counter = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 128; j > 0; j /= 2) {
            if(((*(my_union.bytes+i) / j) % 2) == 1)
                counter++;
        }

    }
    if(counter%2 == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
