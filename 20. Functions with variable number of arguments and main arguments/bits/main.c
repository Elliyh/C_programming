#include <stdio.h>
#include "function.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int main() {
    unsigned long long number;
    number = bits_to_number(NULL, 3, 1,1,1);
    printf("%llu\n", number);
    number = bits_to_number(NULL, 8, 1,0,0,0,0,0,0,1);
    printf("%llu\n", number);
    number = bits_to_number(NULL, 32, 1,1,0,1,0,0,0,1, 0,0,0,0,1,1,0,1, 0,1,0,0,1,0,1,1, 1,1,1,0,1,1,1,0);
    printf("%llu\n", number);
    return 0;
}


