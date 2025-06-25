#include <stdio.h>

int main() {
    int T[10];
    int i;
    int* ukaz = T;
    for (i = 0; i < 10; i++)
    {
        *ukaz = i;
        printf("%d ", *ukaz);
        ukaz++;
    }

    return 0;
}
