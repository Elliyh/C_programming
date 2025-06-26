#include <stdio.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    printf("Enter numbers: ");
    int x, y, tryb;
    int (*funcs[4])(int, int) = {add_int, sub_int, div_int, mul_int};
    if(scanf("%d %d", &x, &y) != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    printf("Choose an operation:");
    if(scanf("%d", &tryb) != 1)
    {
        printf("Incorrect input");
        return 1;
    }
    else if(tryb != 0 && tryb != 1 && tryb != 2 && tryb != 3)
    {
        printf("Incorrect input data");
        return 2;
    }

    printf("Result: %d", calculate(x, y, *(funcs+tryb)));
    return 0;
}

