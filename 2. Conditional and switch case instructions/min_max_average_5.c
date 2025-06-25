#include <stdio.h>

int main() {
    float i1, i2, i3, i4, i5, naj_m, naj_w;
    printf("podaj 5 liczb:\n");
    int p = scanf("%f %f %f %f %f", &i1, &i2, &i3, &i4 ,&i5);

    if (p != 5)
    {
        printf("Wpisano nieprawidlowe dane!");
        return 1;
    }
    if (i1<i2)
        naj_m = i1;
    else
        naj_m = i2;
    if (naj_m < i3)
        naj_m = naj_m;
    else
        naj_m = i3;
    if (naj_m < i4)
        naj_m = naj_m;
    else
        naj_m = i4;
    if (naj_m < i5)
        naj_m = naj_m;
    else
        naj_m = i5;


    if (i1>i2)
        naj_w = i1;
    else
        naj_w = i2;
    if (naj_w > i3)
        naj_w = naj_w;
    else
        naj_w = i3;
    if (naj_w > i4)
        naj_w = naj_w;
    else
        naj_w = i4;
    if (naj_w > i5)
        naj_w = naj_w;
    else
        naj_w = i5;


    printf("%f\n%f\n%.2f", naj_m, naj_w, (i1+i2+i3+i4+i5)/5);
    return 0;
}
