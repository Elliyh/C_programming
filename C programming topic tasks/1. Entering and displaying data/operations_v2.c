#include <stdio.h>

int main() {
    float cislo1 = 69;
    float cislo2 = 97;
    printf("%f %f\n%f\n", cislo1, cislo2, cislo1 * cislo2);
    printf("%.2f\n%f\n%f", cislo1 / cislo2, cislo1+cislo2, cislo1-cislo2);

    return 0;
}
