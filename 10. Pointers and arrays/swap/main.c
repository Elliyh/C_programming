#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"

int swap(int *a, int *b)
{
    if (a == NULL || b == NULL)
    {
        return 1;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}

int main() {
    printf("Wpisz 2 liczby int oddzielajac spacja\n");
    int a, b;
    int* u_a = &a;
    int* u_b = &b;
    if(scanf("%d %d", u_a, u_b) != 2)
    {
        printf("Incorrect input");
        return 1;
    }
    swap(u_a, u_b);
    printf("a: %d, b: %d", a, b);




    return 0;
}

