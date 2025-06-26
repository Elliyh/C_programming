#include <stdio.h>

int main() {
    int first_part, second_part_1, second_part_2, second_part_3;
    printf("Podaj numer telefonu:");
    scanf("%d-%d-%d", &second_part_1, &second_part_2, &second_part_3);
    printf("Podaj numer kierunkowy:");
    scanf("%d", &first_part);
    printf("(%s%d) %s%s%d-%s%d-%s%d", (first_part>10) ? "" : "0", first_part,

           (second_part_1>100) ?  "" : "0" , (second_part_1<10) ?  "0" : "", second_part_1,

           (second_part_2>10) ?  "" : "0" ,
           second_part_2, (second_part_3>10) ?  "" : "0", second_part_3);


    return 0;
}
