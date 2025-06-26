#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"


struct point_t{
    int x;
    int y;
};




int my_printf(char *input, ...)
{
    if(input == NULL)
        return -1;

    int count_print = 0;
    int count_input = 0;
    va_list args;
    va_start(args, input);
    while(*(input+count_input))
    {
        if(*(input+count_input) == '%')
        {
            count_input++;
            if(*(input+count_input) == 's')
            {
                char* text = va_arg(args, char*);
                int i = 0;
                while(*(text+i) != '\0')
                {
                    putc(*(text+i), stdout);
                    count_print++;
                    i++;
                }
            }
            else if(*(input+count_input) == 'd')
            {
                int number = va_arg(args, int);
                if(number < 0)
                {
                    putc('-', stdout);
                    count_print++;
                    number*=-1;
                }
                int new_number = number;
                int len = 1;
                while(new_number >= 10)
                {
                    new_number/=10;
                    len*=10;
                }
                while(len)
                {
                    putc((int)((int)number/len)+'0', stdout);
                    count_print++;
                    number = number - (len*(int)(number/len));
                    len/=10;
                }
            }
            else if(*(input+count_input) == 'f')
            {
                double number = va_arg(args, double);
                if(number < 0)
                {
                    putc('-', stdout);
                    count_print++;
                    number*=-1;
                }
                int first_part = (int)number;
                count_print += my_printf("%d", first_part);
                putc('.', stdout);
                count_print++;
                int second_part = (int)((number-(double)first_part)*100000);
                int len = 10000;
                while(len)
                {
                    putc((int)((int)second_part/len)+'0', stdout);
                    count_print++;
                    second_part = second_part - (len*(int)(second_part/len));
                    len/=10;
                }

            }
            else if(*(input+count_input) == 'p')
            {
                struct point_t punkt = va_arg(args, struct point_t);
                putc('(', stdout);
                count_print++;
                int number = punkt.x;
                count_print+= my_printf("%d", number);
                putc(' ', stdout);
                count_print++;
                number = punkt.y;
                count_print+=my_printf("%d", number);
                putc(')', stdout);
                count_print++;
            }
        }
        else
        {
            count_print++;
            putc(*(input+count_input), stdout);
        }
        count_input++;
    }
    va_end(args);
    return count_print;
}

int my_scanf(char *input, ...)
{
    if(input == NULL)
        return -1;

    int count_read = 0;
    int count_input = 0;
    va_list args;
    va_start(args, input);
    while(*(input+count_input))
    {
        if(*(input+count_input) == '%')
        {
            count_input++;

            if(*(input+count_input) == 'd')
            {
                int* number = va_arg(args, int*);
                *number = 0;
                int flag = 1;
                int c;
                while(1)
                {
                    c = getchar();
                    while(c == ' ')
                        c = getchar();
                    if(c == '+' || c == '-' || isdigit(c))
                    {
                        if(c == '-')
                            flag = -1;
                        if(isdigit(c))
                        {
                            *number = *number * 10 + c - '0';
                        }
                        break;
                    }
                    if(c != '+' && c!= '-' && !isdigit(c))
                        break;
                }
                if(c != '+' && c!= '-' && !isdigit(c))
                    continue;
                c = getchar();
                while(isdigit(c))
                {
                    *number = *number * 10 + c - '0';
                    c = getchar();
                }
                *number *= flag;
                count_read++;
            }
            else if(*(input+count_input) == 'f')
            {
                double* number = va_arg(args, double*);
                *number = 0;
                int flag = 1;
                int c;
                while(1)
                {
                    c = getchar();
                    while(c == ' ')
                        c = getchar();
                    if(c == '+' || c == '-' || isdigit(c))
                    {
                        if(c == '-')
                            flag = -1;
                        if(isdigit(c))
                        {
                            *number = *number * 10 + c - '0';
                        }
                        break;
                    }
                    if(c != '+' && c!= '-' && !isdigit(c))
                        break;
                }
                if(c != '+' && c!= '-' && !isdigit(c))
                    continue;
                c = getchar();
                while(isdigit(c))
                {
                    *number = *number * 10 + c - '0';
                    c = getchar();
                }
                if(c == '.')
                {
                    double k = 0.1;
                    c = getchar();
                    while(isdigit(c))
                    {
                        *number = *number + k*(c - '0');
                        k *= 0.1;
                        c = getchar();
                    }
                }
                else
                    ungetc(c, stdin);
                *number *= flag;
                count_read++;
            }
            else if(*(input+count_input) == 'p')
            {
                struct point_t* punkt = va_arg(args, struct point_t*);
                int c = getchar();
                while(c == ' ')
                    c = getchar();
                if(c != '(')
                    continue;
                if(c == '(')
                {
                    int x = 0, y = 0;
                    int flag = 1;
                    while(1)
                    {
                        while(c == ' ')
                            c = getchar();
                        c = getchar();
                        if(c == '+' || c == '-' || isdigit(c))
                        {
                            if(c == '-')
                                flag = -1;
                            if(isdigit(c))
                            {
                                x = x * 10 + c - '0';
                            }
                            break;
                        }
                    }
                    c = getchar();
                    while(isdigit(c))
                    {
                        x = x * 10 + c - '0';
                        c = getchar();
                    }
                    x *= flag;
                    if(c != ' ')
                    {
                        va_end(args);
                        ungetc(c, stdin);
                        return count_read;
                    }
                    flag = 1;
                    while(1)
                    {
                        c = getchar();
                        while(c == ' ')
                            c = getchar();
                        if(c == '+' || c == '-' || isdigit(c))
                        {
                            if(c == '-')
                                flag = -1;
                            if(isdigit(c))
                            {
                                y = y * 10 + c - '0';
                            }
                            break;
                        }
                        else return 0;
                    }
                    c = getchar();
                    while(isdigit(c))
                    {
                        y = y * 10 + c - '0';
                        c = getchar();
                    }
                    y *= flag;
                    punkt->x = x;
                    punkt->y = y;
                    count_read++;
                    count_read++;
                }
                else
                {
                    va_end(args);
                    ungetc(c, stdin);
                    return count_read;
                }
            }
        }
        count_input++;
    }
    return count_read;

}


int main() {
    my_printf("%d", 400);
    my_printf("%p", (struct point_t){ 211811584, -1081844336 });
    return 0;
}


