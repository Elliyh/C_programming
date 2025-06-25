#include <stdio.h>

#include <math.h>


int main() {
    float a, b;
    printf("Podaj pierwsza przyprostokatna:");
    scanf("%f", &a);
    printf("Podaj druga przyprostokatna:");
    scanf("%f", &b);
    printf("Przeciwprostokatna: %.2f\n", sqrt(pow(a, 2)+pow(b, 2)));
    printf("%.2f\n", (atan(a/b)*180)/3.1415);
    printf("%.2f\n", (atan(b/a)*180)/3.1415);
    return 0;
}
