#include <stdio.h>
#include <math.h>

int main() {
    printf("Podaj 10 liczb:\n");
    double masiv [10];
    for (int j = 0; j < 10; j++)
    {
        if (scanf("%lf", &masiv[j]) != 1)
        {
            printf("incorrect input");
            return 1;
        }
    }
    float suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma += fabs(masiv[i]);
    }
    printf("%.2f", suma);
    return 0;
}
