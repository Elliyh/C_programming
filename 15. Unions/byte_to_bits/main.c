#include <stdio.h>
#include <stdint.h>
#include "bit_set.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    printf("Podaj liczbę:");
    union bit_set my_union;
    if (!scanf("%hhu", &my_union.my_byte)) {
        printf("Incorrect input");
        return 1;
    }
    printf("%hhu %hhu %hhu %hhu %hhu %hhu %hhu %hhu",
            my_union.b7, my_union.b6, my_union.b5, my_union.b4,
            my_union.b3, my_union.b2, my_union.b1, my_union.b0);
    return 0;
}

