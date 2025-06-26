#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    int* tabl = malloc(100*sizeof(int));
    if(tabl == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    int i;
    for(i = 0; i < 100; i++)
    {
        *(tabl+i) = i;
    }
    for(i = 0; i < 100; i++)
    {
        printf("%d ", *(tabl+i));
    }
    free(tabl);
    return 0;
}

