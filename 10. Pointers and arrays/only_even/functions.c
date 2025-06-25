#include "functions.h"
#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int all_even(int number)
{
    if (number < 0)
        number *= -1;
    int ostatok = number % 10;
    if (ostatok % 2 == 0)
    {
        if (number/10 == 0)
        {
            return 1;

        }
        return all_even(number/10);
    }
    else
        return 0;
}

int all_odd(int number)
{
    if (number < 0)
        number *= -1;
    if (number == -1)
        return 1;
    int ostatok = number % 10;
    if (ostatok % 2 == 1)
    {
        if (number/10 == 0)
        {
            return 1;

        }
        return all_odd(number/10);
    }
    else
     return 0;
}

int get_next_number(const int *tab, int size, enum type t)
{
    static const int* actual_tab = NULL;
    static int actual_index = 0;
    static int actual_size = 0;
    if (tab != NULL) {
        actual_tab = tab;
        actual_index = 0;
        actual_size = size;
    }
    if (actual_size <= 0)
        return -2;
    if(tab == NULL)
    {
        actual_index++;
    }
    if (tab == NULL && actual_tab == NULL)
        return -2;
    if (actual_index+1 > actual_size)
        return -1;
    if(t == ALL_ODD)
    {
        if (*(actual_tab+actual_index) == -1)
            return -1;
        else if (all_odd(*(actual_tab+actual_index)) == 1)
            return *(actual_tab+actual_index);
        else
            return get_next_number(NULL, actual_size, t);

    }
    else if (t == ALL_EVEN)
    {
        if (*(actual_tab+actual_index) == -1)
            return -1;
        else if (all_even(*(actual_tab+actual_index)) == 1)
            return *(actual_tab+actual_index);
        else
            return get_next_number(NULL, actual_size, t);
    }
    else if(t == MIX)
    {
        if (*(actual_tab+actual_index) == -1)
            return -1;
        else if (all_even(*(actual_tab+actual_index)) == 0 && all_odd(*(actual_tab+actual_index)) == 0)
            return *(actual_tab+actual_index);
        else
            return get_next_number(NULL, actual_size, t);
    }
    return -2;
}
