#include <stdio.h>
#include "for_loop.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int main() {
    //for_loop(0, 10, 40, print_square);
    double start, krok, stop;
    printf("Podaj poczatek, krok i koniec przedzialu:");
    if(scanf("%lf %lf %lf", &start, &krok, &stop) != 3)
    {
        printf("Incorrect input");
        return 1;
    }
    if((start < stop && krok <= 0) || (start > stop && krok >= 0))
    {
        printf("Incorrect input data");
        return 2;
    }
    printf("Podaj rodzaj operacji");
    int tryb;
    if(!scanf("%d", &tryb))
    {
        printf("Incorrect input");
        return 1;
    }
    if(tryb <0 || tryb > 3)
    {
        printf("Incorrect input data");
        return 2;
    }
    void (*mods[])(double) = {print_value, print_accumulated, print_square, print_abs};
    for_loop(start, krok, stop, mods[tryb]);
    return 0;
}




