#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


int stack_init(struct stack_t **stack)
{
    if(stack == NULL)
        return 1;
    *stack = calloc(1, sizeof(struct stack_t));
    if(*stack == NULL)
    {
        return 2;
    }
    (*stack)->head = NULL;
    return 0;
}
int stack_push(struct stack_t *stack, int value)
{
    if(stack == NULL)
        return 1;

    struct node_t *end = calloc(1, sizeof(struct node_t));
    if (end == NULL)
        return 2;

    end->data = value;
    end->next = stack->head;
    stack->head = end;

    return 0;
}
void stack_display(const struct stack_t* stack)
{
    if (stack == NULL) {
        return;
    }

    struct node_t *temp = stack->head;
    /*if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }*/

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int stack_pop(struct stack_t* stack, int *err_code)
{
    if (stack == NULL || stack->head == NULL) {
        if (err_code != NULL) {
            *err_code = 1;
        }
        return 0;
    }

    struct node_t *temp = stack->head;
    int value = temp->data;
    stack->head = temp->next;
    free(temp);
    if(err_code != NULL)
        *err_code = 0;
    return value;
}

void stack_destroy(struct stack_t** stack)
{
    if(stack == NULL || *stack == NULL)
    {
        return;
    }

    struct node_t* temp = (*stack) -> head;
    while(temp != NULL)
    {
        struct node_t* temp2 = temp->next;
        free(temp);
        temp = temp2;
    }
    free(*stack);
    *stack = NULL;

}
int stack_empty(const struct stack_t* stack)
{
    if(stack == NULL)
    {
        return 2;
    }
    if(stack->head != NULL)
        return 0;
    return 1;
}

