#include <stdio.h>

int main() {
    float money;
    int month;
    printf("podaj kwote poczatkowa:");
    if (scanf("%f", &money) == 0 || money < 0)
    {
        printf("incorrect input");
        return 1;
    }
    printf("podaj liczbe miesiecy:");
    if (scanf("%d", &month) == 0 || month < 0)
    {
        printf("incorrect input");
        return 1;
    }
    while (month > 0)
    {
        money = money + (money*0.01);
        month--;
    }
    printf("kwota koncowa: %.2f", money);
    return 0;
}
