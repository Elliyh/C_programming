#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    printf("Podaj wartości a:");
    scanf("%d", &a);
    printf("Podaj wartości b:");
    scanf("%d", &b);
    printf("Podaj wartości c:");
    scanf("%d", &c);
    printf("%.2f", sqrt(pow(a, 2)+pow(b, 2)+pow(c, 2)));
    return 0;
}
