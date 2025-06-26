#include <stdio.h>
#include "functions.h"
#include "tested_declarations.h"
#include "rdebug.h"

DEFINE_ARRAY(int)
CREATE_ARRAY(int)
FREE_ARRAY(int)
SAVE_ARRAY(int)
LOAD_ARRAY(int)
SORT_ARRAY(int)

DEFINE_ARRAY(double)
CREATE_ARRAY(double)
FREE_ARRAY(double)
SAVE_ARRAY(double)
LOAD_ARRAY(double)
SORT_ARRAY(double)

int main() {


    char* filename = calloc(31, sizeof(char));
    if(filename == NULL)
    {
        printf("Failed to allocate memory");
        return 8;
    }
    for (int i = 0; i < 31; i++)
        *(filename+i) = '\0';

    printf("Enter filename:");
    scanf("%30[^\n]", filename);
    int type;
    printf("Choose your type:");
    if(!scanf("%d", &type))
    {
        printf("Incorrect input");
        free(filename);
        return 1;
    }
    if(type != 0 && type != 1)
    {
        printf("Incorrect input data");
        free(filename);
        return 2;
    }
    if(type == 0)
    {
        struct array_int_t * my_struct;
        int spraw = load_array_int(&my_struct, filename);
        if(spraw == 1)
        {
            printf("Incorrect input data");
            free(filename);
            free_array_int(my_struct);
            return 2;
        }
        else if(spraw == 2)
        {
            printf("Couldn't open file");
            free(filename);
            return 4;
        }
        else if(spraw == 3)
        {
            printf("File corrupted");
            free(filename);
            return 6;
        }
        else if(spraw == 4)
        {
            printf("Failed to allocate memory");
            free(filename);
            if(my_struct!= NULL)
                free_array_int(my_struct);
            return 8;
        }
        spraw = sort_array_int(my_struct);
        if(spraw == 1)
        {
            printf("Incorrect input data");
            free(filename);
            if(my_struct!= NULL)
                free_array_int(my_struct);
            return 2;
        }
        spraw = save_array_int(my_struct, filename);
        if(spraw == 1)
        {
            printf("Incorrect input data");
            free(filename);
            free_array_int(my_struct);
            return 2;
        }
        else if(spraw == 2)
        {
            printf("Couldn't create file");
            free(filename);
            free_array_int(my_struct);
            return 5;
        }
        free_array_int(my_struct);
    }
    else
    {
        struct array_double_t * my_struct;
        int spraw = load_array_double(&my_struct, filename);
        if(spraw == 1)
        {
            printf("Incorrect input data");
            free_array_double(my_struct);
            free(filename);
            return 1;
        }
        else if(spraw == 2)
        {
            printf("Couldn't open file");
            free(filename);
            return 4;
        }
        else if(spraw == 3)
        {
            printf("File corrupted");
            free(filename);
            return 6;
        }
        else if(spraw == 4)
        {
            printf("Failed to allocate memory");
            free(filename);
            free_array_double(my_struct);
            return 8;
        }
        spraw = sort_array_double(my_struct);
        if(spraw == 1)
        {
            printf("Incorrect input data");
            free(filename);
            free_array_double(my_struct);
            return 2;
        }
        spraw = save_array_double(my_struct, filename);
        if(spraw == 1)
        {
            printf("Incorrect input data");
            free(filename);
            free_array_double(my_struct);
            return 2;
        }
        else if(spraw == 2)
        {
            printf("Couldn't create file");
            free(filename);
            free_array_double(my_struct);
            return 5;
        }
        free_array_double(my_struct);
    }
    printf("File saved");
    free(filename);
    return 0;
}

