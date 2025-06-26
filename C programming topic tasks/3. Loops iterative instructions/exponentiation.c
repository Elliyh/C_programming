#include <stdio.h>

int main() {
    int i;
    double sum;
    for (i = 0, sum = 1; i <= 19; i++, sum *= 10)
        printf("%0.f ", sum);

    return 0;
}
