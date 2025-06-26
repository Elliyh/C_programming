#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL));
    float T[20];
    int i;
    float* ukaz = T;
    for (i = 0; i < 20; i++)
    {
        *ukaz = (float)rand() / RAND_MAX;
        printf("%.2f ", *ukaz);
        ukaz++;
    }

    printf("\n");
    ukaz = T;

    for (i = 0; i < 10; i++)
    {
        printf("%.2f ", *ukaz);
        ukaz+=2;
    }


    return 0;
}
