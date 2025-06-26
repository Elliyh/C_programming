#include <stdio.h>
#include "vector_utils.h"
#include "tested_declarations.h"
#include "rdebug.h"





int main() {
    printf("Podaj wektor:");
    int tab [150] = {0};
    int* T = tab;
    int size = read_vector(T, 150, 0);
    if (size == 150)
    {
        int a;
        while((a = getchar()) != '\n'){};
    }
    if (size == -1 || size == 0)
    {
        printf("Not enough data available");
        return 3;
    }
    else if (size == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("Podaj przesuniecie:");

    int skok;
    if (!scanf("%d", &skok))
    {
        printf("Incorrect input");
        return 1;
    }


    printf("podaj kierunek przesuniecia:");
    int kierunek;
    if (!scanf("%d", &kierunek))
    {
        printf("Incorrect input");
        return 1;
    }
    else if (kierunek != 1 && kierunek != 2)
    {
        printf("Incorrect input data");
        return 2;
    }

    enum direction dir;
    if (kierunek == 1)
        dir = ROTATE_RIGHT;
    else
        dir = ROTATE_LEFT;



    shift(T, size, skok, dir);

    display_vector(T, size);



    return 0;
}

