#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"



int main(int count_args, char* args[]) {

    if (count_args < 2)
    {
        printf("Not enough arguments");
        return 9;
    }

    int i;
    for(i = 1; i < count_args; i++)
    {
        struct stack_t* ukaz;
        int spraw = stack_load(&ukaz, *(args+i));
        switch (spraw)
        {
            case 2:
                printf("Couldn't open file %s\n", *(args+i));
                stack_destroy(&ukaz);
                continue;
            case 3:
                printf("Failed to allocate memory");
                stack_destroy(&ukaz);
                return 8;
            default:
                spraw = stack_save(ukaz, *(args+i));
                if(spraw == 2)
                {
                    printf("Couldn't create file");
                    stack_destroy(&ukaz);
                    return 5;
                }
                printf("File %s saved\n", *(args+i));
                stack_destroy(&ukaz);
        }
    }

    return 0;
}



