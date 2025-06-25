#include <stdio.h>

int main() {
    printf("Podaj tekst:\n");
    char massiv [100];
    int i, proverka = 0;
    for (i = 0; i < 100; i++)
    {
        scanf("%c", &massiv[i]);
        if (massiv[i] == '\n')
        {
            break;
        }
        if ((massiv[i] != 43 && massiv[i] != 45) && (massiv[i] < 48 || massiv[i] > 57))
        {
            proverka += 1;
        }

    }
    if (proverka != 0)
    {
        printf("Incorrect input");
        return 1;
    }
    int liczba = 0, j, g = 0;
    int massiv_int [100] = {0};
    int sum;
    for (j = 0; j < i+1; j++) {
        if (massiv[j] >= '0' && massiv[j] <= '9') {
            liczba = liczba * 10 + (massiv[j] - '0');
        }
        else {
            massiv_int[g] = liczba;
            liczba = 0;
            g += 1;
        }
    }
    g = 0;
    sum = massiv_int [0];
    for (j = 0; j < i; j++)
    {

        if (massiv[j] == 43)
        {
            sum += massiv_int[g+1];
            g += 1;
        }
        else if (massiv[j] == 45)
        {
            sum -= massiv_int[g+1];
            g += 1;
        }
    }
    printf("%d", sum);
    return 0;
}
