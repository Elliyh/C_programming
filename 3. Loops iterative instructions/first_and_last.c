#include <stdio.h>
#include <math.h>

int main() {
    printf("Ppdaj liczbe typu unsigned long long:\n");
    unsigned long long liczba;
    char bykv = '\n';
    if (scanf("%llu%c", &liczba, &bykv) && bykv == '\n')
    {
        if (liczba == 0)
        {
            printf("Pierwsza liczba: %llu\n", liczba);
            printf("Ostatnia liczba: %llu\n", liczba);
            return 0;
        }
        long long il_des = log10(liczba);
        long long il_deq = pow(10, il_des);
        printf("Pierwsza liczba: %llu\n", liczba/il_deq);
        printf("Ostatnia liczba: %llu\n", liczba%10);
    }
    else
    {printf("incorrect input");
        return 1;}
    return 0;
}
