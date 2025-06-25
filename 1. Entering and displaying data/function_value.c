#include <stdio.h>
#include <math.h>

float func(float x){
    float graf = (2*pow(x, 3)) - (4*pow(x, 2)) + 3*x - 7;
    return graf;
}

int main() {
    printf("podaj liczbę: ");
    float perem;
    scanf("%f", &perem);
    printf("wartosc funkcji y=%.6f", func(perem));
    return 0;
}
