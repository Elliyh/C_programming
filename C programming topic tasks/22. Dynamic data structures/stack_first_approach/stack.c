#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"


int stack_init(struct stack_t **stack, int N)
{
    if(stack == NULL || N <= 0)
        return 1;
    *stack = calloc(1, sizeof(struct stack_t));
    if(*stack == NULL)
        return 2;
    (*stack)->capacity = N;
    (*stack)->head = 0;
    (*stack)->data = calloc(N, sizeof(int));
    if((*stack)->data == NULL)
    {
        free(*stack);
        *stack = NULL;
        return 2;
    }
    return 0;
}


int stack_push(struct stack_t *stack, int value)
{
    if(stack == NULL || stack->data == NULL || stack->head < 0 || stack->capacity <= 0 || stack->head > stack->capacity)
        return 1;
    if(stack->head == stack->capacity)
    {
        int* new_data = realloc(stack->data, sizeof(int)*stack->capacity*2);
        if(new_data == NULL)
            return 2;
        stack->capacity *= 2;
        stack->data = new_data;
    }
    *(stack->data+stack->head) = value;
    stack->head += 1;

    return 0;
}
int stack_pop(struct stack_t *stack, int *err_code)
{
    if(err_code != NULL)
        *err_code = 0;
    if(stack == NULL || stack->data == NULL || stack->head < 0 || stack->capacity <= 0 || stack->head > stack->capacity)
    {
        if(err_code != NULL)
            *err_code = 1;
        return 1;
    }
    if(stack->head == 0)
    {
        if(err_code != NULL)
            *err_code = 2;
        return 2;
    }
    int number = *(stack->data+stack->head-1);
    stack->head -= 1;
    return number;
}

void stack_display(const struct stack_t *stack)
{
    if(stack == NULL || stack->data == NULL || stack->head < 0 || stack->capacity <= 0 || stack->head > stack->capacity)
    {
        return;
    }
    if(stack->head == 0)
    {
        return;
    }
    for(int i = stack->head-1; i >= 0; i--)
    {
        printf("%d ", *(stack->data+i));
    }
    printf("\n");
}


void stack_free(struct stack_t *stack)
{
    if(stack == NULL)
        return;
    if(stack->data != NULL)
        free(stack->data);
    free(stack);
}


