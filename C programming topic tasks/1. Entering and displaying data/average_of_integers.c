#include <stdio.h>

int main() {
    int sred_aryt [10];
    printf("Podaj dziesiec liczb:\n");
    scanf("%d %d %d %d %d %d %d %d %d %d", &sred_aryt[0], &sred_aryt[1], &sred_aryt[2],
    &sred_aryt[3], &sred_aryt[4], &sred_aryt[5], &sred_aryt[6], &sred_aryt[7], &sred_aryt[8], &sred_aryt[9]);
    float sred = (sred_aryt[0]+sred_aryt[1]+sred_aryt[2]+
    sred_aryt[3]+sred_aryt[4]+sred_aryt[5]+sred_aryt[6]+sred_aryt[7]+sred_aryt[8]+sred_aryt[9])/10.0;
    printf("Srednia arytmetyczna= %.4f", sred);
    return 0;
}
