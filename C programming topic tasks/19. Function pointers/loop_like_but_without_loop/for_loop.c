#include <stdio.h>
#include <stdlib.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"



void for_loop(double start, double krok, double stop, void (*printer)(double))
{
    if((start < stop && krok < 0) || (start > stop && krok > 0))
    {
        return;
    }
    static double new_start;
    static double number;
    static int counter = 0;
    if(printer == NULL || krok == 0)
    {
        return;
    }

    if(new_start != start)
    {
        counter = 0;
    }
    if(((krok < 0 && stop >= number+krok) || (krok > 0 && stop <= number+krok)) && counter != 0)
        return;
    if(counter == 0)
    {
        number = start;
        new_start = start;
    }
    else
    {
        number += krok;
    }
    printer(number);
    counter++;
    for_loop(start, krok, stop, printer);
}

void print_value(double number)
{
    printf("%f ", number);
}

void print_accumulated(double number)
{
    static double new_number;
    static int counter = 0;
    if(counter == 0)
    {
        new_number = number;
        printf("%.6f ", new_number);
    }
    else
    {
        new_number += number;
        printf("%.6f ", new_number);
    }
    counter++;
}

void print_square(double number)
{
    printf("%.6f ", number*number);
}

void print_abs(double number)
{
    if(number < 0 )
        number = -number;
    printf("%.6f ", number);
}



