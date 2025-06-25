#include <stdio.h>

int main() {
    int silnia;
    int long long kon = 1;
    printf("Podaj liczbe:");
    if (scanf("%d", &silnia) == 1 && silnia < 21 && silnia >= 0)
    {
        for (int i = 1; i <= silnia; i++)
        {
            kon=kon*i;
        }
        if (silnia == 0 || silnia == 1)
        {
            printf("%d", 1);
            return 0;
        }
        printf("%lld", kon);
    }
    else
    {
        printf("incorrect input");
        return 1;
    }
    return 0;
}
