#include <stdio.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"


int main()
{
    struct stack_t* ukaz;
    int spraw = stack_init(&ukaz);
    if(spraw == 2)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    while(1)
    {
        printf("Co chcesz zrobic?");
        int choice;
        if(!scanf("%d", &choice))
        {
            printf("Incorrect input");
            stack_destroy(&ukaz);
            return 1;
        }
        switch (choice)
        {
            case 0:
                stack_destroy(&ukaz);
                return 0;
            case 1:
                printf("Podaj liczbe");
                int number;
                if(!scanf("%d", &number))
                {
                    stack_destroy(&ukaz);
                    printf("Incorrect input");
                    return 1;
                }
                spraw = stack_push(ukaz, number);
                if(spraw == 2)
                {
                    stack_destroy(&ukaz);
                    printf("Failed to allocate memory");
                    return 8;
                }
                break;
            case 2:
                spraw = stack_empty(ukaz);
                if(spraw == 1)
                {
                    printf("Stack is empty\n");
                    break;
                }
                int value = stack_pop(ukaz, &spraw);
                printf("%d\n", value);
                break;
            case 3:
                spraw = stack_empty(ukaz);
                if(spraw == 1)
                {
                    printf("%d\n", 1);
                    break;
                }
                else
                {
                    printf("%d\n", 0);
                    break;
                }
            case 4:
                spraw = stack_empty(ukaz);
                if(spraw == 1)
                {
                    printf("Stack is empty\n");
                    break;
                }
                stack_display(ukaz);
                printf("\n");
                break;
            default:
                printf("Incorrect input data\n");
                break;
        }
    }
}


