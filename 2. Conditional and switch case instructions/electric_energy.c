#include <stdio.h>

int main() {
    printf("Podaj ilosc kWh:");
    int kwh;
    float netto;
    if (scanf("%d", &kwh) != 1 || kwh < 0)
    {
        printf("Incorrect input");
        return 1;
    }
    else
    {
        if (kwh <= 50)
        {
            netto = kwh*0.50;
        } else if (kwh <= 150)
        {
            netto = 50*0.5 + (kwh - 50)*0.75;
        } else if (kwh <= 250)
        {
            netto = 50*0.5 + 100*0.75 + (kwh - 150) *1.20;
        } else
        {
            netto = 50*0.5 + 100*0.75 + 100*1.20 + (kwh - 250)*1.50;
        }
    }
    printf("Koszt brutto: %.6f", netto+netto*0.22);
    return 0;
}
