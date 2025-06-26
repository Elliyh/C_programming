#include <stdio.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"






int main() {
    printf("Enter data type:");
    int type;
    if(!scanf("%d", &type))
    {
        printf("Incorrect input");
        return 1;
    }
    if(type != 0 && type != 1 && type != 2) {
        printf("Incorrect input data");
        return 2;
    }
    unsigned long zero = 0;
    unsigned long one = 0;
    unsigned int number_4;
    unsigned short number_2;
    unsigned long number_8;
    printf("Enter an integer number:");
    switch (type)
    {
        case 0:
            if(!scanf("%u", &number_4))
            {
                printf("Incorrect input");
                return 1;
            }
            COUNT_BITS(number_4, &one, &zero);
            printf("%lu\n%lu\n", one, zero);
            DISPLAY_BITS(number_4);
            printf("\n");
            REVERSE_BITS(&number_4);
            DISPLAY_BITS(number_4);
            break;

        case 1:
            if(!scanf("%hu", &number_2))
            {
                printf("Incorrect input");
                return 1;
            }
            COUNT_BITS(number_2, &one, &zero);
            printf("%lu\n%lu\n", one, zero);
            DISPLAY_BITS(number_2);
            printf("\n");
            REVERSE_BITS(&number_2);
            DISPLAY_BITS(number_2);
            break;

        case 2:
            if(!scanf("%lu", &number_8))
            {
                printf("Incorrect input");
                return 1;
            }
            COUNT_BITS(number_8, &one, &zero);
            printf("%lu\n%lu\n", one, zero);
            DISPLAY_BITS(number_8);
            printf("\n");
            REVERSE_BITS(&number_8);
            DISPLAY_BITS(number_8);
            break;
    }

    return 0;
}



