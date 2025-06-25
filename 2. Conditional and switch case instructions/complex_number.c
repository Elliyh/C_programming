#include <stdio.h>
#include <math.h>

int main() {
    int real, imag;
    char znak;
    printf("Podaj liczbe zespolona:");
    int proverka = scanf("%d%ci%d", &real, &znak, &imag);
    if (proverka != 3 || imag<0)
    {
        printf("Incorrect input");
        return 1;
    }
    else
    {
        if (znak != '-' && znak != '+')
        {
            printf("Incorrect input");
            return 1;
        }
        printf("Czesc rzeczywista: %d\n", real);
        if (znak == '-')
        {
            printf("Czesc urojona: -%d", imag);
        }
        else if (znak == '+')
        {
            printf("Czesc urojona: %d", imag);
        }
    }
    return 0;
}
