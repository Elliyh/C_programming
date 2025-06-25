#include <stdio.h>
#include <math.h>

char znak_znak(double pervoe, double vtoroe) //SUMA i Mnoz
{
    float sum = pervoe + vtoroe;
    int odin = ((fabs(sum)+0.001) / (sum+0.001)) + 1;
    char plus_minus[3] = {'-', '+', '+'};
    char znak = plus_minus[odin];
    return znak;
}

void vivod(double mnim, double ril1) //vivod 00000
{
    double modul_mnim = fabs(mnim);
    int odin = ((modul_mnim+0.001) / (mnim+0.001)) + 1;

    char plus_minus[3] = {'-', '+', '+'};
    char znak = plus_minus[odin];
    printf("%c%.3lf %c i%.3lf\n", znak_znak(ril1, ril1), fabs(ril1), znak, modul_mnim);
}

void umnoz(double ril1, double ril2, double mnim1, double mnim2) //Mnoz
{
    double per_por = (ril1 * ril2) - (mnim1 * mnim2);
    double vtor_por = (ril1 * mnim2) + (ril2 * mnim1);

    printf("Iloczyn: %c%.3lf %c i%.3lf\n", znak_znak(per_por, per_por), fabs(per_por),
           znak_znak(vtor_por, vtor_por), fabs(vtor_por));
}

char znak_minus(double pervoe, double vtoroe)
{
    float delen = pervoe - vtoroe;
    int odin = ((fabs(delen)+0.001) / (delen+0.001)) + 1;
    char plus_minus[3] = {'-', '+', '+'};
    char znak = plus_minus[odin];
    return znak;
}

int znak_lok_del(double peremen)
{
    double modul_mnim = fabs(peremen);
    int odin = (modul_mnim / peremen); //oshibka
    return odin; ////-1
}

void delen(double ril1, double ril2, double mnim1, double mnim2)
{
    double cast_ril = (ril1 * ril2 - mnim1 * (-mnim2));
    double cast_mnim = ril1 * (-mnim2) + mnim1 * ril2;

    double modul_low = ril2 * ril2 + mnim2 * mnim2;

    double del_real = cast_ril / modul_low;
    double del_im = cast_mnim / modul_low;

    printf("Iloraz: %c%.3lf %c i%.3lf", znak_znak(del_real, del_real), fabs(del_real),
           znak_znak(del_im, del_im), fabs(del_im));
}

int main()
{
    double ril1, ril2, mnim1, mnim2;
    printf("Podaj czesc rzeczywista pierwszej liczby zespolonej:\n");
    scanf("%lf", &ril1);
    printf("Podaj czesc urojona pierwszej liczby zespolonej:\n");
    scanf("%lf", &mnim1);
    printf("Podaj czesc rzeczywista drugiej liczby zespolonej:\n");
    scanf("%lf", &ril2);
    printf("Podaj czesc urojona drugiej liczby zespolonej:\n");
    scanf("%lf", &mnim2);

    printf("Pierwsza liczba zespolona to: ");
    vivod(mnim1, ril1);
    printf("Druga liczba zespolona to: ");
    vivod(mnim2, ril2);

    printf("Suma: %c%.3lf", znak_znak(ril1, ril2), fabs(ril1 + ril2));
    printf(" %c i%.3lf\n", znak_znak(mnim1, mnim2), fabs(mnim1 + mnim2));
    printf("Roznica: %c%.3lf", znak_minus(ril1, ril2), fabs(ril1 - ril2));
    printf(" %c i%.3lf\n", znak_minus(mnim1, mnim2), fabs(mnim1 - mnim2));

    umnoz(ril1, ril2, mnim1, mnim2);

    delen(ril1, ril2, mnim1, mnim2);
}


//float per_por_v = (ril1 * ril2) - (mnim1 * mnim2);
//int izm_znak = znak_lok_del(mnim2) * (ril1*mnim2);
//printf("%d", izm_znak);
//float vtor_por_v = mnim1*ril2; //+(-1*per_por_v) // znak_lok_del(mnim2)*


//float per_por_n = (ril2*ril2) + (mnim2*mnim2);
//printf("%.3f %.3f %.3f", per_por_v, vtor_por_v, per_por_n);
//float result_per_por = per_por_v/per_por_n;
//float result_vtor_por = vtor_por_v/per_por_n; //per_por_v -pervyi potyadok niz ////s 00000 problema