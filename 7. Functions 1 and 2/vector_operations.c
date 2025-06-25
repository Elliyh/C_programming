#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int read_vector(int vec[], int size, int stop_value)
{
    int i;
    int rozmiar = 0;
    if (size <= 0)
        return -1;
    for (i = 0; i < size; i++)
    {
        if (scanf("%d", &vec[rozmiar]) == 1)
        {
            if (vec[rozmiar] == stop_value)
            {
                break;
            }
            rozmiar += 1;
        }
        else
            return -2;
    }

    if (i <= 50)
    {
        int a;
        while((a=getchar()) != '\n'){}
    }
    return rozmiar;

}

void display_vector(const int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", vec[i]);
    }
}

int concat_begin(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (first == NULL || second == NULL || size <= 0 || size2 <= 0 || size3 <= 0)
    {
        return -1;
    }
    if (size + size2 > size3)
        return -2;

    int j;
    for (j = 0; j < size; j++)
    {

        dest[j] = first[j];
    }

    for (int g = 0; g+j < size+size2; g++)
    {
        dest[g+j] = second[g];
    }
    return size+size2;

}


int concat_end(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (first == NULL || second == NULL || size <= 0 || size2 <= 0 || size3 <= 0)
    {
        return -1;
    }
    if (size + size2 > size3)
        return -2;

    int j;
    for (j = 0; j < size2; j++)
    {
        dest[j] = second[j];
    }

    for (int g = 0; g+j < size+size2; g++)
    {
        dest[g+j] = first[g];
    }
    return size+size2;
}

int concat_zip(const int first[], int size, const int second[], int size2, int dest[], int size3)
{
    if (first == NULL || second == NULL || size <= 0 || size2 <= 0 || size3 <= 0)
    {
        return -1;
    }
    if (size + size2 > size3)
        return -2;

    int l1 = 0, l2 = 0;
    for (int i = 0; i < size+size2; i++)
    {
        if (i < size)
        {
            dest[l1+l2] = first[i];
            l1 += 1;
        }
        if (i < size2)
        {
            dest[l1+l2] = second[i];
            l2 += 1;
        }
    }
    return size+size2;
}


int main() {

    int wektor1[50] = {0}, wektor2[50] = {0}, wektor3[50]= {0};

    printf("podaj pierwszy wektor:");
    int size1 = read_vector(wektor1, 50, 0);

    if (size1 == 0)
    {
        printf("not enough data available");
        return 2;
    }

    if (size1 == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    printf("podaj drugi wektor:");

    int size2 = read_vector(wektor2, 50, 0);

    if (size2 == 0)
    {
        printf("not enough data available");
        return 2;
    }

    if (size2 == -2)
    {
        printf("Incorrect input");
        return 1;
    }

    if (size1+size2>50)
    {
        display_vector(wektor1, size1);
        printf("\n");
        display_vector(wektor2, size2);
        printf("\nOutput buffer is too small");
        return 0;
    }

    display_vector(wektor1, size1);
    printf("\n");
    display_vector(wektor2, size2);
    printf("\n");

    int max_size3 = 50;
    int gg_size = concat_begin(wektor1, size1, wektor2, size2, wektor3, max_size3);
    display_vector(wektor3, gg_size);
    printf("\n");
    concat_end(wektor1, size1, wektor2, size2, wektor3, max_size3);
    display_vector(wektor3, gg_size);
    printf("\n");
    concat_zip(wektor1, size1, wektor2, size2, wektor3, max_size3);
    display_vector(wektor3, gg_size);
    //concat_zip((int[]){2, 10, -8, 2, -7, 2, 9, -2, -10}, 9, (int[]){-5}, 1, wektor3, 10);

    return 0;
}

