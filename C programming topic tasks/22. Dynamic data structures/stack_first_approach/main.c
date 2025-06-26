#include <stdio.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"

int main() {
    struct stack_t* ukaz;
    int spraw = stack_init(&ukaz, 10);
    int err_code = 0;
    if(spraw == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    while(1)
    {
        printf("Co chcesz zrobic?");
        int action;
        if(!scanf("%d", &action))
        {
            printf("Incorrect input");
            stack_free(ukaz);
            return 1;
        }
        switch (action)
        {
            case 0:
                stack_free(ukaz);
                return 0;
            case 1:
                printf("Podaj liczbe");
                int number;
                if(!scanf("%d", &number))
                {
                    printf("Incorrect input");
                    stack_free(ukaz);
                    return 1;
                }
                spraw = stack_push(ukaz, number);
                if(spraw == 2)
                {
                    printf("Failed to allocate memory");
                    stack_free(ukaz);
                    return 8;
                }
                break;
            case 2:
                spraw = stack_pop(ukaz, &err_code);
                if(err_code == 2)
                {
                    printf("Stack is empty\n");
                    break;
                }
                printf("%d\n", spraw);
                break;
            case 3:
                if(ukaz->head == 0)
                {
                    printf("Stack is empty\n");
                    break;
                }
                stack_display(ukaz);
                break;
            default:
                printf("Incorrect input data\n");
        }
    }
    stack_free(ukaz);
    return 0;
}


