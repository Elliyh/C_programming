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

int (*get_function(enum tryb operation))(int, int)
{
    if (operation < op_add || operation > op_mul)
        return NULL;
    static int (*funcs[])(int, int) = {add_int, sub_int, div_int, mul_int};



    return *(funcs+operation);
}
