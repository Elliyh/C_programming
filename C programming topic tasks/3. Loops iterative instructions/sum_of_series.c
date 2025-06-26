#include <stdio.h>

double func(int n)
{
    return 1.0/(n*(n+1));
}


int main() {
    double suma = 0;
    int prob;
    for (int i = 1; func(i) > 10e-5; i++)
    {
        prob = i;
        suma += func(i);
    }
    printf("%d %.4lf", prob, suma);
    return 0;
}
