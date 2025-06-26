#include <stdio.h>
#include "byte_set.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    union byte_set my_union;

    printf("Podaj liczbe:");
    if(!scanf("%d", &my_union.number))
    {
        printf("Incorrect input");
        return 1;
    }

    for (int i = 0; i < (int)sizeof(int); i++) {
        printf("%d ", *(my_union.show_byte+i));
    }

    return 0;
}
