#include <stdio.h>

int main() {
    double i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, naj_m, naj_w;
    printf("podaj 5 liczb:\n");

    scanf("%lf", &i1);
    int j = 1;
    if (i1 != -1.000000)
    {
        scanf("%lf", &i2);
        j += 1;
        if (i2 != -1.000000)
        {
            scanf("%lf", &i3);
            j += 1;
            if (i3 != -1.000000)
            {
                scanf("%lf", &i4);
                j += 1;
                if (i4 != -1.000000)
                {
                    scanf("%lf", &i5);
                    j += 1;
                }
            }
        }

    }

    if (i1<i2 || i2 == -1)
        naj_m = i1;
    else
        naj_m = i2;
    if (naj_m < i3 && i3 != -1 && i2 != -1)
        naj_m = naj_m;
    else if (naj_m > i3 && i3 != -1 && i2 != -1)
        naj_m = i3;
    if (naj_m < i4 && i3 != -1 && i4 != -1 && i2!=-1)
        naj_m = naj_m;
    else if (naj_m > i4 && i3 != -1 && i4 != -1 && i2 != -1)
        naj_m = i4;
    if (naj_m < i5 && i3 != -1 && i4 != -1 && i5 != -1 && i2 != -1)
        naj_m = naj_m;
    else if (naj_m > i5 && i3 != -1 && i4 != -1 && i5 != -1 && i2 != -1)
        naj_m = i5;


    if (i1>i2 || i2 == -1)
        naj_w = i1;
    else
        naj_w = i2;
    if (naj_w > i3 && i3 != -1 && i2 != -1)
        naj_w = naj_w;
    else if (naj_w < i3 && i3 != -1 && i2 != -1)
        naj_w = i3;
    if (naj_w > i4 && i3 != -1 && i4 != -1 && i2 != -1)
        naj_w = naj_w;
    else if (naj_w < i4 && i3 != -1 && i4 != -1 && i2 != -1)
        naj_w = i4;
    if (naj_w > i5 && i3 != -1 && i4 != -1 && i5 != -1 && i2 != -1)
        naj_w = naj_w;
    else if (naj_w < i5 && i3 != -1 && i4 != -1 && i5 != -1 && i2 != -1)
        naj_w = i5;

    double masiv [5] = {i1, i2, i3, i4, i5};
    if (masiv[j-1] == -1)
        masiv[j-1] = 0;
    else
        j+=1;
    printf("%lf\n%lf\n%.2lf\n", naj_m, naj_w, (masiv[0]+masiv[1]+masiv[2]+masiv[3]+masiv[4])/(j-1));
    return 0;
}
