#include <stdio.h>
#include <string.h>
#include "vector_utils.h"
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main() {
    printf("Podaj liczby:");
    int massive[100];
    int size = read_vector(massive, 100, -1);

    if (size == -2)
    {
        printf("Incorrect input");
        return 1;
    }
    if (size == 0)
    {
        printf("Not enough data available");
        return 3;
    }

    int i, liczba;
    for (i = 0; i < size; i++)
    {
        if (i == 0)
            liczba = get_next_number(massive, size, ALL_ODD);
        else
            liczba = get_next_number(NULL, size, ALL_ODD);
        if (liczba == -1 && i == 0)
        {
            printf("Nothing to show");
            break;
        }
        if (liczba == -1)
            break;
        printf("%d ", liczba);
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        if (i == 0)
            liczba = get_next_number(massive, size, ALL_EVEN);
        else
            liczba = get_next_number(NULL, size, ALL_EVEN);
        if (liczba == -1 && i == 0)
        {
            printf("Nothing to show");
            break;
        }
        if (liczba == -1)
            break;
        printf("%d ", liczba);
    }
    printf("\n");
    for (i = 0; i < size; i++)
    {
        if (i == 0)
            liczba = get_next_number(massive, size, MIX);
        else
            liczba = get_next_number(NULL, size, MIX);
        if (liczba == -1 && i == 0)
        {
            printf("Nothing to show");
            break;
        }
        if (liczba == -1)
            break;
        printf("%d ", liczba);
    }

    /*const int input_array[] = {19, 959, 9535, 337951, 99355, 711, 53, 373, 31199, 315315, 39, 13};
    const int to_find_array[] = {ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD, ALL_ODD};
    const int expected_array[] = {19, 959, 9535, 337951, 99355, 711, 53, 373, 31199, 315315, 39, 13, -1};


    printf("#####START#####");
    int res = get_next_number(input_array, 12, to_find_array[0]);
    printf("#####END#####");

    printf("Funkcja get_next_number() powinna zwrócić wartość %d; a zwróciła %d\n", expected_array[0], res);

    for (int i = 1; i < 13; ++i)
    {
        int res = get_next_number(NULL, -100, to_find_array[i]);
        printf("Funkcja get_next_number() powinna zwrócić wartość %d; a zwróciła %d\n", expected_array[i], res);
    }*/


    return 0;
}
