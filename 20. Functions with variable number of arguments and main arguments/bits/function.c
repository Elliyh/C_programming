#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <stdlib.h>
#include "function.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

unsigned long long bits_to_number(int* err_code, int count, ...)
{
    if(err_code != NULL)
        *err_code = 0;
    if(count <= 0 || count > 64)
    {
        if(err_code != NULL)
            *err_code = 1;
    }
    va_list bits;
    va_start(bits, count);
    unsigned long long number = 0;
    for(int i = 0; i < count; i++)
    {
        int bit = va_arg(bits, int);
        if(bit != 1 && bit != 0)
        {
            if(err_code != NULL)
                *err_code = 1;
            va_end(bits);
            return 0;
        }
        if(bit == 1)
        {
            unsigned long long potega= 1;
            for(int j = 0; j < count-i-1; j++)
            {
                potega *= 2;
            }
            number += potega;
        }
    }
    va_end(bits);
    return number;
}

