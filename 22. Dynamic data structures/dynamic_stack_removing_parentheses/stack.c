#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"





int stack_push(struct stack_t **stack, char value)
{
    if(stack == NULL)
        return 1;

    struct stack_t* ukaz = calloc(1, sizeof(struct stack_t));
    if(ukaz == NULL)
        return 2;

    ukaz->prev = *stack;
    ukaz->character = value;
    *stack = ukaz;
    return 0;
}


char stack_pop(struct stack_t **stack, int *err_code)
{
    if(stack == NULL || *stack == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return '-';
    }

    char temp = (*stack)->character;
    struct stack_t* temp_ukaz = *stack;
    *stack = (*stack)->prev;
    free(temp_ukaz);
    if(err_code != NULL)
        *err_code = 0;
    return temp;
}


void stack_destroy(struct stack_t **stack)
{
    if(stack == NULL || *stack == NULL)
        return;
    while(*stack != NULL)
    {
        struct stack_t* temp_ukaz = *stack;
        *stack = (*stack)->prev;
        free(temp_ukaz);
    }
    *stack = NULL;
}

void stack_display(const struct stack_t *stack)
{
    if(stack == NULL)
        return;
    struct stack_t * temp = (struct stack_t *)stack;
    while(temp != NULL)
    {
        printf("%c ", temp->character);
        temp = temp->prev;
    }
}

int stack_empty(const struct stack_t *stack)
{
    if(stack)
        return 0;
    return 1;
}


