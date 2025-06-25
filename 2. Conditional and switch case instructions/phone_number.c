#include <stdio.h>

int main() {
    int first_part, second_part_1, second_part_2, second_part_3;
    printf("Podaj numer telefonu:");
    int proverka = scanf("(%d) %d-%d-%d)", &first_part, &second_part_1, &second_part_2, &second_part_3);
    if (proverka != 4)
    {
        printf("Incorrect input");
        return 1;
    }
    else{
        printf("Numer kierunkowy: %02d\n", first_part);
        printf("Numer telefonu: %03d-%02d-%02d", second_part_1, second_part_2, second_part_3);
    }

    return 0;
}
