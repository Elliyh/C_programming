#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tested_declarations.h"
#include "rdebug.h"
//#include "tested_declarations.h"
//#include "rdebug.h"

int* count_words(const char *filename, int *err_code, int N, ...)
{
    if(err_code != NULL)
        *err_code  = 0;
    if(filename == NULL || N <= 0)
    {
        if(err_code != NULL)
            *err_code  = 1;
        return NULL;
    }
    int *statistic = calloc(N, sizeof(int));
    if(statistic == NULL)
    {
        if(err_code != NULL)
            *err_code  = 3;
        return NULL;
    }
    FILE *f = fopen(filename, "r");
    if(f == NULL)
    {
        if(err_code != NULL)
            *err_code  = 2;
        free(statistic);
        return NULL;
    }
    va_list args;
    va_start(args, N);
    for(int i = 0; i < N; i++)
    {
        char* current_word = va_arg(args, char*);
        int current_word_length = (int)strlen(current_word);
        char c;
        int current = 0, previous = 0;
        int j, current_length;
        do{
            c = getc(f);
            current = isalpha(c)?1:0;
            if(current == 1 && previous == 0)
            {
                current_length = 0;
            }
            if(current == 1)
                current_length ++;
            if(current == 0 && previous == 1)
            {
                if(current_word_length == current_length)
                {
                    fseek(f, -current_length-1, SEEK_CUR);
                    int same_letter = 0;
                    for(j = 0; j < current_length; j++)
                    {
                        c = getc(f);
                        if(c == *(current_word+j))
                            same_letter++;
                    }
                    if(same_letter == current_word_length)
                        *(statistic+i) += 1;
                }
            }
            previous = current;
        } while(c != EOF);
        rewind(f);
    }
    fclose(f);
    va_end(args);
    return statistic;
}

int main(int count_arguments, char* arguments[])
{


    if(count_arguments < 3)
    {
        printf("Not enough arguments");
        return 9;
    }

    char* filename = *(arguments+1);
    char** word_list = arguments+2;
    int err;
    int cnt_words = count_arguments - 2;
    for(int i = 0; i < cnt_words; i++)
    {
        int* counts = count_words(filename, &err, 1, *(word_list+i));
        switch (err) {
            case 2:
                printf("Couldn't open file");
                return 4;
            case 3:
                printf("Failed to allocate memory");
                return 8;
            case 1:
                printf("Not enough arguments");
                return 9;
            default:
                break;
        }
        printf("%d\n", *(counts+0));
        free(counts);
    }


    return 0;
}


