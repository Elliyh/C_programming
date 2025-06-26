#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <ctype.h>
#include <string.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int priority(char sym)
{
    if(sym == '+' || sym == '-')
        return 1;
    else if(sym == '*' || sym == '/')
        return 2;
    return 0;
}


int main() {
    printf("Enter expression:");

    char* text = NULL;
    long unsigned int size = 0;
    struct stack_t* ukaz = NULL;

    int read_sym = getline(&text, &size, stdin);
    if(read_sym == -1) {
        printf("Incorrect input");
        return 1;
    }
    *(text + read_sym - 1) = '\0';

    int i = 0;
    while(*(text + i) != '\0') {
        if(*(text + i) != ' ' && !isdigit(*(text + i)) && *(text + i) != '(' && *(text + i) != ')'
           && *(text + i) != '/' && *(text + i) != '*'&& *(text + i) != '-' && *(text + i) != '+')
        {
            printf("Incorrect input");
            return 1;
        }
        i++;
    }

    char* token = strtok(text, " ");

    while(token != NULL) {
        if(strlen(token) != 1 || isdigit(*token))
        {
            printf("%s ", token);
        }
        else
        {
            if(ukaz == NULL)
            {
                if(stack_push(&ukaz, *token) == 2)
                {
                    stack_destroy(&ukaz);
                    printf("Failed to allocate memory");
                    return 8;
                }
            }
            else if(*token == '(')
            {
                if(stack_push(&ukaz, *token) == 2)
                {
                    stack_destroy(&ukaz);
                    printf("Failed to allocate memory");
                    return 8;
                }
            }
            else if(*token == ')')
            {
                char sym = stack_pop(&ukaz, NULL);
                while(sym != '(')
                {
                    printf("%c ", sym);
                    sym = stack_pop(&ukaz, NULL);
                }
            }
            else
            {
                int precedence_token = priority(*token);
                while(ukaz && ukaz->character != '(' && priority(ukaz->character) >= precedence_token)
                {
                    printf("%c ", stack_pop(&ukaz, NULL));
                }
                if(stack_push(&ukaz, *token) == 2)
                {
                    stack_destroy(&ukaz);
                    printf("Failed to allocate memory");
                    return 8;
                }
            }
        }
        token = strtok(NULL, " ");
    }

    while(ukaz) {
        char sym = stack_pop(&ukaz, NULL);
        printf("%c ", sym);
    }
    stack_destroy(&ukaz);

    return 0;
}


