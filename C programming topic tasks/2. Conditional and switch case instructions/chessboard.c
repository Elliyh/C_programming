#include <stdio.h>

int main() {
    printf("Podaj pole:");
    char lit;
    int cyfr;
    scanf("%c%d", &lit, &cyfr);
    int char_i = (int)lit;
    if (char_i <= 104 && char_i >= 97 && cyfr >= 1 && cyfr <= 8)
    {
        if((char_i - cyfr)%2==0)
        {
            printf("black");
        }
        else
            printf("white");
    }
    else
    {
        printf("Incorrect input");
        return 1;
    }

    return 0;
}
