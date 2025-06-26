#include <stdio.h>
#include <stdlib.h>
#include "int_operations.h"
#include "tested_declarations.h"
#include "rdebug.h"


int add_int(int a, int b)
{
    return a + b;
}

int sub_int(int a, int b)
{
    return a - b;
}

int div_int(int a, int b)
{
    if(b == 0)
        return 0;
    return a / b;
}

int mul_int(int a, int b)
{
    return a * b;
}

int calculate(int a, int b, int (*funcs)(int, int))
{
    return funcs(a, b);
}
