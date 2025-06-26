#include <stdio.h>
#include <math.h>

double discr(double a, double b, double c)
{
    return (b*b)-(4*a*c);
}


int main() {
    printf("Program rozwiązujący równanie kwadratowe postaci 0 = ax^2 + bx + c\n");
    double a, b, c;
    printf("Podaj a:");
    scanf("%lf", &a);
    printf("Podaj b:");
    scanf("%lf", &b);
    printf("Podaj c:");
    scanf("%lf", &c);

    if (a == 0 && b == 0 && c == 0)
    {
        printf("nieskonczonosc");
    }
    else if (discr(a, b, c) < 0 || (a==0 && b==0))
        printf("brak");

    else if (a == 0)
    {
        printf("jeden pierwiastek %.6lf", -c/b);
    }
    else if (discr(a, b, c) == 0)
    {
        printf("jeden pierwiastek %.6lf", -b/(2*a));
    }
    else if (discr(a, b ,c) > 0) {
        double discr1 = discr(a, b, c);
        double discr2 = discr(a, b, c);
        printf("dwa pierwiastki: %.6f %.6f", (-b + sqrt(discr1)) / (2 * a),
               (-b - sqrt(discr2)) / (2 * a));
    }
    return 0;
}
