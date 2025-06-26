#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tested_declarations.h"
#include "rdebug.h"

void display_vector(const int vec[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", vec[i]);
    }
}

int generate(int lotto[], int N, int start, int end)
{
    if (start == end && N == 1)
    {
        lotto[0] = end;
        return 0;
    }
    if (start+N>end)
    {
        return -1;
    }
    srand(time(NULL));
    int i;
    for (i = 0; i < N; i++)
    {
        lotto[i] = start + (rand() % abs(end-start));
        for (int j = i-1; j >= 0; j--)
        {
            if (lotto[i] == lotto[j])
            {
                i -= 1;
            }
        }
    }
    return 0;
}


int main()
{
    int massive [6];
    generate(massive, 6, 1, 49);
    display_vector(massive, 6);
    return 0;
}

