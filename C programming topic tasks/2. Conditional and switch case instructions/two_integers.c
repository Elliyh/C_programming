#include <stdio.h>

int main() {
    int first, second;
    printf("Podaj dwie liczby całkowite oddzielone spacją:");
    int proverka = scanf("%d %d", &first, &second);
    if (proverka == 2)
    {
        printf("%d", first+second);
    }
    else
    {printf("Incorrect input");
        return 1;}
    return 0;
}
