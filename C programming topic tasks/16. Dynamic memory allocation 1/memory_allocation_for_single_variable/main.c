#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    float* tabl = malloc(sizeof(float));
    if(tabl == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    *tabl = M_PI;
    printf("%f %p", *tabl, (void *)tabl);
    free(tabl);
    return 0;
}

