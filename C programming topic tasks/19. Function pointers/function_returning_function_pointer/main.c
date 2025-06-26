#include <stdio.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    printf("Enter numbers: ");
    int x, y, tryb;
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
    enum tryb my_tryb = tryb;
    printf("Result: %d", get_function(my_tryb)(x, y));
    return 0;
}

