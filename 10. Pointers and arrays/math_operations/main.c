#include <stdio.h>
#include "tested_declarations.h"
#include "rdebug.h"


int add(const int *first, const int *second, int *result)
{
    if (first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }
    *result = *first + *second;
    return 0;
}

int subtract(const int *first, const int *second, int *result)
{
    if (first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }
    *result = *first - *second;
    return 0;
}

int multiply(const int *first, const int *second, int *result)
{
    if (first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }
    *result = *first * *second;
    return 0;
}

int divide(const int *first, const int *second, float *result)
{
    if (first == NULL || second == NULL || result == NULL)
    {
        return 1;
    }
    if (*second == 0)
    {
        return 1;
    }
    *result = (float)(*first) / (float)*second;
    return 0;
}


int main() {
    printf("Podaj działanie:");
    int a, b;
    char c;
    int result = 0;
    float res = 0;
    float* u_res_float = &res;
    int* u_res = &result;
    char* u_c = &c;
    int* u_a = &a;
    int* u_b = &b;
    if(scanf("%d%c%d", u_a, u_c, u_b) != 3)
    {
        printf("Incorrect input");
        return 1;
    }
    else if (*u_c != '/' && *u_c != '*' && *u_c != '+' && *u_c != '-')
    {
        printf("Incorrect input");
        return 1;
    }
    switch (c)
    {
        case '+':
            add(u_a, u_b, u_res);
            printf("%d", *u_res);
            break;
        case '-':
            subtract(u_a, u_b, u_res);
            printf("%d", *u_res);
            break;
        case '*':
            multiply(u_a, u_b, u_res);
            printf("%d", *u_res);
            break;
        case '/':
            if(divide(u_a, u_b, u_res_float) == 1)
            {
                printf("operation not permitted");
                return 4;
            }

            printf("%f", *u_res_float);
            break;

    }


    return 0;
}

