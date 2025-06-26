#include <stdio.h>

int main() {
    float sred_aryt [5];
    printf("Podaj 5 liczb:\n");
    scanf("%f %f %f %f %f", &sred_aryt[0], &sred_aryt[1], &sred_aryt[2],
    &sred_aryt[3], &sred_aryt[4]);
    printf("Wynik: %.4f", (sred_aryt[0]+sred_aryt[1]+sred_aryt[2]+sred_aryt[3]+sred_aryt[4])/5);
    return 0;
}
