#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"




int stack_push(struct stack_t **stack, char *value)
{
    if(stack == NULL || value == NULL)
        return 1;

    struct stack_t* ukaz = calloc(1, sizeof(struct stack_t));
    if(ukaz == NULL)
        return 2;

    ukaz->prev = *stack;
    ukaz->sentence = value;
    *stack = ukaz;
    return 0;
}


char *stack_pop(struct stack_t **stack, int *err_code)
{
    if(stack == NULL || *stack == NULL)
    {
        if(err_code != NULL)
            *err_code = 1;
        return NULL;
    }

    char* temp_text = (*stack)->sentence;
    struct stack_t* temp_ukaz = *stack;
    *stack = (*stack)->prev;
    free(temp_ukaz);
    if(err_code != NULL)
        *err_code = 0;
    return temp_text;
}


void stack_destroy(struct stack_t **stack)
{
    if(stack == NULL || *stack == NULL)
        return;
    while(*stack != NULL)
    {
        struct stack_t* temp_ukaz = *stack;
        *stack = (*stack)->prev;
        if(temp_ukaz->sentence != NULL)
            free(temp_ukaz->sentence);
        free(temp_ukaz);
    }
    *stack = NULL;
}
int stack_load(struct stack_t **stack, const char *filename)
{
    if(stack == NULL || filename == NULL || *stack != NULL)
        return 1;
    FILE *f = fopen(filename, "r");
    if(f == NULL)
        return 2;
    int count_sym = 0;
    char c;
    while(1)
    {
        c = fgetc(f);
        count_sym++;
        if(c == EOF)
        {
            fclose(f);
            return 0;
        }

        if(c == '.')
        {

            fseek(f, -count_sym, SEEK_CUR);
            char* temp_text = calloc(count_sym+1, sizeof(char));
            if(temp_text == NULL)
            {
                fclose(f);
                stack_destroy(stack);
                return 3;
            }
            fscanf(f, "%[^.]", temp_text);


            c = getc(f);
            *(temp_text+count_sym-1)= c;
            *(temp_text+count_sym) = '\0';

            if(stack_push(stack, temp_text) == 2)
            {
                fclose(f);
                free(temp_text);
                stack_destroy(stack);
                return 3;
            }
            count_sym = 0;
        }
    }
}
int stack_save(const struct stack_t *stack, const char *filename)
{
    if(stack == NULL || filename == NULL)
    {
        return 1;
    }
    FILE *f = fopen(filename, "w");
    if(f == NULL)
    {
        return 2;
    }
    struct stack_t * temp = (struct stack_t *)stack;
    while(temp != NULL)
    {
        fwrite(temp->sentence, sizeof(char), strlen(temp->sentence), f);
        //fwrite(".", sizeof(char), 1, f);
        temp = temp->prev;
    }
    fclose(f);
    return 0;
}


