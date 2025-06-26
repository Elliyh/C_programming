#include <stdio.h>

int main() {
    double sum = 1;
    for (int i = 0; i <= 19; i++, sum *= 10) {
        printf("10 do potegi %2d = %20.0f\n", i, sum);
    }

    return 0;
}
